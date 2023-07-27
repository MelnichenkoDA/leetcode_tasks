#include "pch.h"

#include <design/ParkingSystem.h>

TEST(ParkingSystem, leet)
{
	design::ParkingSystem parkings(1, 1, 0);
	EXPECT_EQ(parkings.addCar(1), true);
	EXPECT_EQ(parkings.addCar(2), true);
	EXPECT_EQ(parkings.addCar(3), false);
	EXPECT_EQ(parkings.addCar(1), false);
}