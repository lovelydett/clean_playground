/**
 * @file implement2.cpp
 * @author Yuting Xie (xyt@bupt.cn)
 * @brief reader writer problem (writer-prior) with 1 mutex and 2 cv
 * @version 0.1
 * @date 2023-05-21
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <random>
#include <vector>
#include <chrono>

/**
 * @brief The status of current reader/writer is protected by a mutex
 * 
 */
struct Status {
    int read_count = 0;
    int write_count = 0;
} status;
std::mutex mtx;
std::condition_variable cv_can_read;
std::condition_variable cv_can_write;

int critical_data = 0;

void reader() {
    std::random_device rd;
    while (true) {
        std::this_thread::sleep_for(std::chrono::milliseconds(rd() % 1000));
        std::unique_lock<std::mutex> lck(mtx);
        /* now we own the mutex, can check status*/
        while (status.write_count > 0) {
            /* when there is still writer, need to wait for all writers to finish */
            cv_can_read.wait(lck);
        }
        /**
         * at this point, we can assure that:
         * 1. there is no writer
         * 2. we own the mutex for status
         * so we modify the status 
         */
        status.read_count++;

        /* release the mutex so other (readers) can proceed */
        lck.unlock();
        std::cout << "reader " << std::this_thread::get_id() << " read " << critical_data << std::endl;

        /* finish reading, lock the mutex to modify status */
        lck.lock();
        status.read_count--;
        if (status.read_count == 0) {
            /* no current reader, notify a writer */
            cv_can_write.notify_one();
        }
    }
}

void writer() {
    std::random_device rd;
    while (true) {
        std::this_thread::sleep_for(std::chrono::milliseconds(rd() % 1000));
        /* lock the mutex to check status */
        std::unique_lock<std::mutex> lck(mtx);
        status.write_count++;
        while (status.read_count > 0) {
            /* there are readers or other writers */
            cv_can_write.wait(lck);
        }
        /**
         * at this point, we can assure that: we are the only writer
         * so we can keep the write_count status and release the mutex, and write critical data
         */
        lck.unlock();
        critical_data = rd() % 1000;
        std::cout << "writer " << std::this_thread::get_id() << " write " << critical_data << std::endl;

        /* modify the status again */
        lck.lock();
        status.write_count--;
        if (status.write_count == 0) {
            /* no other writer, notify all waiting readers */
            cv_can_read.notify_all();
        } else {
            /* there are waiting writers, notify one of them */
            cv_can_write.notify_one();
        }
    }
}

int num_reader = 10;
int num_writer = 3;

int main(int argc, char** argv) {
    if (argc == 3) {
        num_reader = atoi(argv[1]);
        num_writer = atoi(argv[2]);
    } else {
        std::cout << "Usage: " << argv[0] << " num_reader num_writer" << std::endl;
        return 0;
    }
    std::vector<std::thread> threads;
    threads.reserve(num_reader + num_writer);
    for (int i = 0; i < num_reader; ++i) {
        threads.emplace_back(reader);
    }
    for (int i = 0; i < num_writer; ++i) {
        threads.emplace_back(writer);
    }
    for (auto& t : threads) {
        t.join();
    }
    return 0;
}