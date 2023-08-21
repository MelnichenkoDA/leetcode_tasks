#include "pch.h"

#include "math/PowerOfTwo.h"

TEST(PowerOfTwo, leet)
{
	EXPECT_EQ(math::isPowerOfTwo(16), true);
	EXPECT_EQ(math::isPowerOfTwo(1024), true);
	EXPECT_EQ(math::isPowerOfTwo(1), true);
	EXPECT_EQ(math::isPowerOfTwo(32), true);
	EXPECT_EQ(math::isPowerOfTwo(3), false);
	EXPECT_EQ(math::isPowerOfTwo(-16), false);
}