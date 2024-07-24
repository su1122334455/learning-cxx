#include "../exercise.h"
#include <iostream>

class DynFibonacci {
    size_t *cache;
    int cached;

public:
    // TODO: 实现动态设置容量的构造器
    DynFibonacci(int capacity) : cache(new size_t[capacity]), cached(0) {
        // 初始化缓存的前两个值
        if (capacity > 0) {
            cache[0] = 0;
            cached = 1;
        }
        if (capacity > 1) {
            cache[1] = 1;
            cached = 2;
        }
        // 计算后续的斐波那契数列值
        for (int i = 2; i < capacity; ++i) {
            cache[i] = cache[i - 1] + cache[i - 2];
        }
    }

    // TODO: 实现复制构造器
    DynFibonacci(const DynFibonacci &other) = delete;

    // TODO: 实现析构器，释放缓存空间
    ~DynFibonacci() {
        delete[] cache;
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

    // NOTICE: 不要修改这个方法
    // NOTICE: 名字相同参数也相同，但 const 修饰不同的方法是一对重载方法，可以同时存在
    //         本质上，方法是隐藏了 this 参数的函数
    //         const 修饰作用在 this 上，因此它们实际上参数不同
    size_t get(int i) const {
        if (i <= cached) {
            return cache[i];
        }
        ASSERT(false, "i out of range");
    }
};

int main(int argc, char **argv) {
    DynFibonacci fib(12);
    ASSERT(fib.get(10) == 55, "fibonacci(10) should be 55");
    // 由于复制构造函数被禁用，以下行会导致编译错误
    // DynFibonacci const fib_ = fib;
    return 0;
}