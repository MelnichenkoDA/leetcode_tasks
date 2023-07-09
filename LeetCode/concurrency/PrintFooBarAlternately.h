#pragma once
#include <functional>
#include <atomic>

namespace concurrency
{
    class FooBar {
    private:
        std::atomic<bool> showFoo{ true };
        int n;

    public:
        FooBar(int n) {
            this->n = n;
        }

        void foo(std::function<void()> printFoo) 
        {
            for (int i = 0; i < n; i++) 
            {
                while (true)
                {
                    if (showFoo.load())
                    {
                        printFoo();
                        showFoo.store(false);
                        break;
                    }
                    std::this_thread::yield();
                }
            }
        }

        void bar(std::function<void()> printBar) 
        {
            for (int i = 0; i < n; i++) 
            {
                while (true)
                {
                    if (!showFoo.load())
                    {
                        printBar();
                        showFoo.store(true);
                        break;
                    }
                    std::this_thread::yield();
                }
            }
        }

    };
}
