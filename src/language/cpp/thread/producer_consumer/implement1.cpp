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
    } 
    
}

