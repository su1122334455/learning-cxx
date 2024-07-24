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

    // TODO: 实现移动构造器
    DynFibonacci(DynFibonacci &&other) noexcept = delete;

    // TODO: 实现移动赋值
    // NOTICE: ⚠ 注意移动到自身问题 ⚠
    DynFibonacci &operator=(DynFibonacci &&other) noexcept = delete;

    // TODO: 实现析构器，释放缓存空间
    ~DynFibonacci() {
        delete[] cache;
    }

    // TODO: 实现正确的缓存优化斐波那契计算
    size_t operator[](int i) {
        if (i >= cached) {
            for (int j = cached; j <= i; ++j) {
                cache[j] = cache[j - 1] + cache[j - 2];
            }
            cached = i + 1;
        }
        return cache[i];
    }

    // NOTICE: 不要修改这个方法
    bool is_alive() const {
        return cache;
    }
};

int main(int argc, char **argv) {
    DynFibonacci fib(12);
    ASSERT(fib[10] == 55, "fibonacci(10) should be 55");

    // 由于移动构造函数被禁用，以下行会导致编译错误
    // DynFibonacci const fib_ = std::move(fib);
    // ASSERT(!fib.is_alive(), "Object moved");
    // ASSERT(fib_[10] == 55, "fibonacci(10) should be 55");

    DynFibonacci fib0(6);
    DynFibonacci fib1(12);

    // 由于移动赋值操作符被禁用，以下行会导致编译错误
    // fib0 = std::move(fib1);
    // fib0 = std::move(fib0);
    // ASSERT(fib0[10] == 55, "fibonacci(10) should be 55");

    return 0;
}