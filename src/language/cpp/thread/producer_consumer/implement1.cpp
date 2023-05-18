/**
 * @file main.cpp
 * @author Yuting Xie (xyt@bupt.cn)
 * @brief implement multi-threaded producer-consumer model with mutex and cv
 * @version 0.1
 * @date 2023-05-18
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <thread>
#include <condition_variable>
#include <mutex>
#include <vector>
#include <cassert>
#include <cstdio>
#include <cstdlib>

std::mutex mtx;
std::condition_variable cv;

int left_count; // This is the critical data
int MAX = 10;

/**
 * @brief producer prints left quote '('
 *
 */
void producer() {
    while (true) {
        std::unique_lock<std::mutex> lck(mtx);
        while (left_count >= MAX) {
            cv.wait(lck);
        }
        // As long as we reach here, two things are dead true:
        // 1. left_count < MAX
        // 2. we are holding the lock.
        assert(left_count < MAX);
        left_count++;
        printf("(");

        // We then notify all consumers and producers.
        cv.notify_all();
    }
}

/**
 * @brief consumer prints right quote ')'
 *
 */
void consumer() {
    while (true) {
        std::unique_lock<std::mutex> lck(mtx);
        while (left_count <= 0) {
            cv.wait(lck);
        }
        // As long as we reach here, two things are dead true:
        // 1. left_count > 0
        // 2. we are holding the lock.
        assert(left_count > 0);
        left_count--;
        printf(")");

        // We then notify all consumers and producers.
        cv.notify_all();
    }
}

int main(int argc, char const *argv[])
{
    int num_threads;
    if (argc > 1) {
        MAX = atoi(argv[1]);
        num_threads = atoi(argv[2]);
        assert(MAX > 0 && num_threads > 0);
    } else {
        MAX = 10;
        num_threads = 10;
    }
    std::vector<std::thread> threads;
    threads.reserve(num_threads * 2);
    for (int i = 0; i < num_threads; i++) {
        threads.push_back(std::thread(producer));
        threads.push_back(std::thread(consumer));
    }
    for (auto &t : threads) {
        t.join();
    }
    return 0;
}