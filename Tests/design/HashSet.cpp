#include "pch.h"

#include <design/HashSet.h>

TEST(HashSet, leet)
{
	design::MyHashSet set;
	set.add(1);
	set.add(2);

	EXPECT_EQ(set.contains(1), true);
	EXPECT_EQ(set.contains(3), false);

	set.add(2);
	EXPECT_EQ(set.contains(2), true);
	set.remove(2);
	EXPECT_EQ(set.contains(2), false);
}