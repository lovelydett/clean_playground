/**
 * @file async.cpp
 * @author Yuting Xie (xyt@bupt.cn)
 * @brief 
 * @version 0.1
 * @date 2023-05-23
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <thread>
#include <iostream>
#include <random>
#include <future>
#include <pthread.h>
#include <vector>

auto get_cpu_core() {
    return sched_getcpu();
}

struct Result {
    float res_;
    unsigned cpu_id_;
};

std::random_device rd;
std::mt19937 gen(rd());

Result monte_carlo_pi(int n) {
    std::uniform_real_distribution<> dis(0.0, 1.0);
    int count = 0;
    float pi = 4.0 / n;
    while (n--) {
        double x = dis(gen);
        double y = dis(gen);
        if (x * x + y * y <= 1) {
            count++;
        }
    }
    return {pi * count, sched_getcpu()};
}

int main() {
    int num_async = std::thread::hardware_concurrency() * 2;
    // Use future to get the result of a function
    std::vector<std::future<Result>> results;
    results.reserve(num_async);
    for (int i = 0; i < num_async; i++) {
        results.push_back(std::async(std::launch::async, monte_carlo_pi, 100000));
    }

    for (auto& result : results) {
        auto res = result.get();
        std::cout << "pi = " << res.res_ << " on CPU " << res.cpu_id_ << std::endl;
    }

    return 0;
}