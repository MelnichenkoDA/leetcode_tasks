#include "pch.h"

#include <format>

#include "concurrency/PrintFooBarAlternately.h"
#include <thread>

namespace
{
    std::string test(int n)
    {
        concurrency::FooBar foo(n);
        std::string res{};
        auto const fooFunc = [&res]() { res = std::format("{}{}", res, "foo"); };
        auto const barFunc = [&res]() { res = std::format("{}{}", res, "bar"); };
        
        std::thread t1(&concurrency::FooBar::foo, &foo, fooFunc);
        std::thread t2(&concurrency::FooBar::bar, &foo, barFunc);

        t1.join();
        t2.join();

        return res;
    }
}

TEST(PrintFooBarAlternately, leet)
{
    EXPECT_EQ(test(1), std::string("foobar"));
    EXPECT_EQ(test(2), std::string("foobarfoobar"));
    EXPECT_EQ(test(5), std::string("foobarfoobarfoobarfoobarfoobar"));
}
