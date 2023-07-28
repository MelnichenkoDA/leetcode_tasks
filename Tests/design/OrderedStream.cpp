#include "pch.h"

#include <design/OrderedStream.h>
#include "../utils/checks.h"


TEST(OrderedStream, leet)
{
	design::OrderedStream stream(5);
	using strings = std::vector<std::string>;

	EXPECT_EQ(stream.insert(3, "ccccc"), strings{});
	EXPECT_EQ(stream.insert(1, "aaaaa"), strings{"aaaaa"});
	EXPECT_EQ(checks::checkEqualStrong(stream.insert(2, "bbbbb"), strings{ {"bbbbb"}, {"ccccc"} }), true);
	EXPECT_EQ(stream.insert(5, "eeeee"), strings{});
	EXPECT_EQ(checks::checkEqualStrong(stream.insert(4, "ddddd"), strings{{"ddddd"}, { "eeeee" }}), true);
}