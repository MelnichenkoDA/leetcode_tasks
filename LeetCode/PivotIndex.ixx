#include <vector>
#include <assert.h>

export module PivotIndex;

export 
namespace PivotIndex
{
    int pivotIndex(std::vector<int>& nums) 
    {
        int sum{};
        for (auto i : nums)
        {
            sum += i;
        }

        int difference{};
        for (int i = 0; i < nums.size(); ++i)
        {
            if (i > 0) difference += nums[i - 1];
            
            sum -= nums[i];

            if (sum == difference) return i;
        }

        return -1;
    }

    void test()
    {
        std::vector<int> first = { 1,7,3,6,5,6 };
        std::vector<int> second = { 1,2,3 };
        std::vector<int> third = { 2,1,-1 };

        assert(pivotIndex(first) == 3);
        assert(pivotIndex(second) == -1 );
        assert(pivotIndex(third) == 0);
    }
}