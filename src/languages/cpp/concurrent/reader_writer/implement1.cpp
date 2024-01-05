/**
 * @file implement1.cpp
 * @author Yuting Xie (xyt@bupt.cn)
 * @brief 
 * @version 0.1
 * @date 2023-05-18
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <mutex>
#include <shared_mutex>
#include <iostream>
#include <thread>
#include <random>
#include <iostream>
#include <random>
#include <vector>

std::shared_mutex smtx;
int reder_count = 0;
int critical_data;
int num_reader = 10;
int num_writer = 3;

void reader() {
    std::random_device rd;
    while (true) {
        {
            std::shared_lock<std::shared_mutex> lock(smtx);
            std::cout << "reader " << std::this_thread::get_id() << " reads " << critical_data << std::endl;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(rd() % 1000));
    }
}

void writer() {
    std::random_device rd;
    while (true) {
        {
            std::unique_lock<std::shared_mutex> lock(smtx);
            critical_data = rd() % 1000;
            std::cout << "writer " << std::this_thread::get_id() << " writes " << critical_data << std::endl;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(rd() % 1000));
    }
}

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