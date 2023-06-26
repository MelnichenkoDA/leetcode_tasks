#include "pch.h"

#include "stack/DailyTemperatures.h"
#include "../utils/checks.h"


TEST(DailyTemperatures, leet)
{
	EXPECT_EQ(checks::checkEqual(stack::dailyTemperatures({ 73, 74, 75, 71, 69, 72, 76, 73 }), { 1,1,4,2,1,1,0,0 }), true);
	EXPECT_EQ(checks::checkEqual(stack::dailyTemperatures({ 30,40,50,60 }), { 1,1,1,0 }), true);
	EXPECT_EQ(checks::checkEqual(stack::dailyTemperatures({ 30,60,90 }), { 1,1,0 }), true);
}