#pragma once

#include <functional>
#include <condition_variable>
#include <mutex>
#include <iostream>

class ZeroEvenOdd {
public:
    ZeroEvenOdd(int n) {
        this->m_num = n;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(std::function<void(int)> printNumber)
    {
        std::unique_lock lock(m_mutex);

        while (currentLessNum())
        {
            m_cond.wait(lock, [this] { return m_zero; });
            m_zero = false;
            printNumber(0);
            m_cond.notify_all();
        }
    }

    void even(std::function<void(int)> printNumber) {
        std::unique_lock lock(m_mutex);

        while (currentLessNum())
        {
            m_cond.wait(lock, [this] { return (!m_zero && checkEven()); });
            m_zero = true;
            printNumber(++m_current);
            m_cond.notify_all();
        }
    }

    void odd(std::function<void(int)> printNumber) {
        std::unique_lock lock(m_mutex);

        while (currentLessNum())
        {
            m_cond.wait(lock, [this] { return (!m_zero && !checkEven()); });
            m_zero = true;
            printNumber(++m_current);
            m_cond.notify_all();
        }
    }

private:
    bool currentLessNum() const { return m_current <= m_num; }
    bool checkEven() const { return (m_current & 1) == 0; }

    std::condition_variable m_cond;
    std::mutex m_mutex;

    int m_num;
    int m_current{};
    bool m_zero{ true };
};

void test()
{
    ZeroEvenOdd foo(5);
    auto const func = [](int n) {std::cout << n; };
    std::thread t1(&ZeroEvenOdd::zero, &foo, func);
    std::thread t2(&ZeroEvenOdd::even, &foo, func);
    std::thread t3(&ZeroEvenOdd::odd, &foo, func);

    t1.join();
    t2.join();
    t3.join();
}
