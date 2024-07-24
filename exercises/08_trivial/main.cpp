#include "../exercise.h"
#include <iostream>

struct FibonacciCache {
    unsigned long long cache[16];
    int cached;
};

// TODO: 实现正确的缓存优化斐波那契计算
static unsigned long long fibonacci(FibonacciCache &cache, int i) {
    // 初始化缓存的前两个值
    if (cache.cached == 0) {
        cache.cache[0] = 0;
        cache.cached = 1;
    }
    if (cache.cached == 1) {
        cache.cache[1] = 1;
        cache.cached = 2;
    }

    // 填充缓存直到达到或超过目标索引 i
    for (; cache.cached <= i; ++cache.cached) {
        cache.cache[cache.cached] = cache.cache[cache.cached - 1] + cache.cache[cache.cached - 2];
    }

    return cache.cache[i];
}

int main(int argc, char **argv) {
    // TODO: 初始化缓存结构体，使计算正确
    // NOTICE: C/C++ 中，读取未初始化的变量（包括结构体变量）是未定义行为
    // READ: 初始化的各种写法 <https://zh.cppreference.com/w/cpp/language/initialization>
    FibonacciCache fib = {{0, 1}, 2}; // 初始化缓存的前两个值，并设置 cached 为 2
    ASSERT(fibonacci(fib, 10) == 55, "fibonacci(10) should be 55");
    std::cout << "fibonacci(10) = " << fibonacci(fib, 10) << std::endl;
    return 0;
}