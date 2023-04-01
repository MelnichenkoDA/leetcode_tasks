#include <vector>
#include <assert.h>

export module SingleNumber;

export namespace SingleNumber
{
    int singleNumber(std::vector<int> const &nums) {
        int res{};
        for (auto i : nums)
        {
            res ^= i;
        }

        return res;
    }

    void test()
    {
        assert(singleNumber({ 2,2,1 }) == 1);
        assert(singleNumber({ 2,3,1,2,3 }) == 1);
        assert(singleNumber({ 4,1,2,1,2 }) == 4);
        assert(singleNumber({ 1 }) == 1);
    }
}