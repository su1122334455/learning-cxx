#include "../exercise.h"
#include <iostream>

class Fibonacci {
    size_t cache[16];
    int cached;

public:
    // TODO: 实现构造器
    Fibonacci() : cache{0, 1}, cached(2) {
        // 初始化缓存的前两个值
        for (int i = 2; i < 16; ++i) {
            cache[i] = cache[i - 1] + cache[i - 2];
        }
    }

    // TODO: 实现正确的缓存优化斐波那契计算
    size_t get(int i) {
        if (i >= cached) {
            for (int j = cached; j <= i; ++j) {
                cache[j] = cache[j - 1] + cache[j - 2];
            }
            cached = i + 1;
        }
        return cache[i];
    }
};

int main(int argc, char **argv) {
    // 现在类型拥有无参构造器，声明时会直接调用。
    // 这个写法不再是未定义行为了。
    Fibonacci fib;
    ASSERT(fib.get(10) == 55, "fibonacci(10) should be 55");
    std::cout << "fibonacci(10) = " << fib.get(10) << std::endl;
    return 0;
}