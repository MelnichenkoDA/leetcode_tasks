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
            if (currentLessNum())
            {
                m_zero = false;
                printNumber(0);
            }
            m_cond.notify_all();
        }
    }

    void even(std::function<void(int)> printNumber) {
        std::unique_lock lock(m_mutex);

        while (currentLessNum())
        {
            m_cond.wait(lock, [this] { return (!m_zero && checkEven()) || !currentLessNum(); });
            if (currentLessNum())
            {
                m_zero = true;
                printNumber(++m_current);
            }
            
            m_cond.notify_all();
        }
    }

    void odd(std::function<void(int)> printNumber) {
        std::unique_lock lock(m_mutex);

        while (currentLessNum())
        {
            m_cond.wait(lock, [this] { return (!m_zero && !checkEven()) || !currentLessNum(); });
            if (currentLessNum())
            {
                m_zero = true;
                printNumber(++m_current);
            }

            m_cond.notify_all();
        }
    }

private:
    bool currentLessNum() const { return m_current < m_num; }
    bool checkEven() const { return (m_current & 1) == 0; }

    std::condition_variable m_cond;
    std::mutex m_mutex;

    int m_num;
    int m_current{};
    bool m_zero{ true };
};
