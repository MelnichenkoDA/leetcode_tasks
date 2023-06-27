#pragma once
#include <vector>
#include <algorithm>
#include <execution>

namespace stack
{
    int carFleet(int target, std::vector<int> const &position, std::vector<int> const &speed)
    {
        std::vector<std::pair<int, int>> cars(position.size());
        
        for (int i = 0; i < position.size(); ++i)
        {
            cars[i].first = position[i];
            cars[i].second = speed[i];
        }
        std::sort(cars.begin(), cars.end(), [](auto left, auto right) {return left.first > right.first; });
        
        double prev = 0;
        int fleetsCount = 0;
        for (int i = 0; i < cars.size(); ++i)
        {
            auto [pos, sp] = cars[i];
            double const turnsTillEnd = (double(target) - pos) / sp;
            if (turnsTillEnd > prev)
            {
                prev = turnsTillEnd;
                ++fleetsCount;
            }
        }

        return fleetsCount;
    }
}