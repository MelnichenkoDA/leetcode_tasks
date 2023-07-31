#include "pch.h"

#include <design/HashMap.h>

TEST(HashMap, leet)
{
	design::MyHashMap map;
	map.put(1, 1);
	map.put(2, 2);
	map.put(150, 5);
	EXPECT_EQ(map.get(1), 1);
	EXPECT_EQ(map.get(3), -1);

	map.put(2, 1);
	EXPECT_EQ(map.get(2), 1);
	map.remove(2);
	EXPECT_EQ(map.get(2), -1);
}