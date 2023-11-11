#include "pch.h"

#include <matrices/SumInMatrix.h>

TEST(SumInMatrices, leetcode)
{
	char a = '0';
	char b = '1';

	bool test = a;
	bool test2 = b;

	EXPECT_EQ(matrices::matrixSum({ {7,2,1} ,{6,4,2},{6,5,3},{3,2,1} }), 15);
	EXPECT_EQ(matrices::matrixSum({ {1} }), 1);
}