export module TwoSum;

import <vector>;
import <cassert>;
import <map>;

export 
namespace TwoSum
{
    std::vector<int> twoSum(std::vector<int> const& nums, int target)
    {
        std::map<int, int> indeces;
        std::vector<int> res(2);
        for (int i = 0; i < nums.size(); ++i)
        {
            auto secondNum = target - nums[i];
            if (auto const secondItr = indeces.find(secondNum); secondItr != indeces.cend())
            {
                res[0] = i;
                res[1] = secondItr->second;
                break;
            }
            indeces[nums[i]] = i;
        }

        return res;
    }

    bool compare(std::vector<int> const& first, std::vector<int> const& second)
    {
        for (auto num : first)
        {
            if (std::find(second.cbegin(), second.cend(), num) == second.cend())
                return false;
        }

        return true;
    }

    void test()
    {
        assert(compare(twoSum({2, 7, 11, 15}, 9), {0, 1}));
        assert(compare(twoSum({3, 2, 4}, 6), {1, 2}));
        assert(compare(twoSum({3, 3}, 6), {0, 1}));
    }
    
}
