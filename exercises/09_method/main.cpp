#include "../exercise.h"
#include <iostream>

struct Fibonacci {
    unsigned long long cache[128];
    int cached;

    // TODO: 实现正确的缓存优化斐波那契计算
    unsigned long long get(int i) {
        // 初始化缓存的前两个值
        if (cached == 0) {
            cache[0] = 0;
            cached = 1;
        }
        if (cached == 1) {
            cache[1] = 1;
            cached = 2;
        }

        // 填充缓存直到达到或超过目标索引 i
        for (; cached <= i; ++cached) {
            cache[cached] = cache[cached - 1] + cache[cached - 2];
        }

        return cache[i];
    }
};

int main(int argc, char **argv) {
    // TODO: 初始化缓存结构体，使计算正确
    Fibonacci fib = {{0, 1}, 2}; // 初始化缓存的前两个值，并设置 cached 为 2
    ASSERT(fib.get(10) == 55, "fibonacci(10) should be 55");
    std::cout << "fibonacci(10) = " << fib.get(10) << std::endl;
    return 0;
}