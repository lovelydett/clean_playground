/**
 * @file implement3.cpp
 * @author Yuting Xie (xyt@bupt.cn)
 * @brief reader writer problem (reader-prior) with 1 mutex and 2 cv
 * @version 0.1
 * @date 2023-05-22
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
    
}