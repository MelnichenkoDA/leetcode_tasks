export module PrintInOrder;

import <functional>;
import <condition_variable>;
import <thread>;
import <iostream>;

export namespace PrintInOrder
{
    class Foo {
    public:
        Foo() {

        }

        void first(std::function<void()> printFirst) {
            printFirst();
            ++m_state;
            cv.notify_all();
        }

        void second(std::function<void()> printSecond) {
            std::unique_lock lock(m_mutex);
            
            cv.wait(lock, [&state = m_state] { 
                return state == 2; 
            });
            printSecond();
            ++m_state;
            lock.unlock();
            cv.notify_all();
        }

        void third(std::function<void()> printThird) {
            std::unique_lock lock(m_mutex);

            cv.wait(lock, [&state = m_state] {
                return state == 3; 
            });
            printThird();
            ++m_state;
            lock.unlock();
            cv.notify_all();
        }

    private:
        std::mutex m_mutex;
        std::condition_variable cv;
        int m_state{1};
    };


    void test()
    {
        Foo f;
        std::thread t1(&Foo::first, &f, [] {std::cout << "first"; });
        std::thread t2(&Foo::second, &f, [] {std::cout << "second"; });
        std::thread t3(&Foo::third, &f, [] {std::cout << "third"; });

        t1.join();
        t2.join();
        t3.join();
    }
}
