#include <vector>
#include <algorithm>
#include <cmath>

namespace binary_search
{
    int minEatingSpeed(std::vector<int> const& piles, int h) 
    {
        int left = 1;
        int right = *(std::max_element(piles.begin(), piles.end()));
        int res = right;
        int eatPerHour = (left + right) >> 1;

        while (left <= right)
        {
            unsigned tempHours = 0;
            for (double curr : piles)
                tempHours += std::ceil(curr / eatPerHour);

            if (tempHours <= h)
            {
                res = std::min(res, eatPerHour);
                right = eatPerHour - 1;
            }                
            else
                left = eatPerHour + 1;

            eatPerHour = (left + right) >> 1;
        }

        return res;
    }
}