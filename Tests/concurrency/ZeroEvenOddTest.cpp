#include "pch.h"

#include "concurrency/ZeroEvenOdd.h"
#include <format>

namespace
{
	std::string test(int n)
	{
        ZeroEvenOdd foo(n);
        std::string res{};
        auto const func = [&res](int n) { res = std::format("{}{}", res,  n); };
        
        std::thread t1(&ZeroEvenOdd::zero, &foo, func);
        std::thread t2(&ZeroEvenOdd::even, &foo, func);
        std::thread t3(&ZeroEvenOdd::odd, &foo, func);

        t1.join();
        t2.join();
        t3.join();

        return res;
	}
}

TEST(ZeroEvenOdd, leet_code)
{
    EXPECT_EQ(test(2), std::string("0102"));
    EXPECT_EQ(test(5), std::string("0102030405"));
}