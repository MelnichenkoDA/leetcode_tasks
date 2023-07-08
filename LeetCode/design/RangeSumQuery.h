#pragma once
#include <vector>

namespace design
{
    class NumArray {
    public:
        NumArray(std::vector<int>&& nums)
            : m_nums(std::move(nums))
        {
            for (int i = 1; i < m_nums.size(); ++i)
                m_nums[i] += m_nums[i - 1];
        }

        int sumRange(int left, int right) 
        {
            if (left == 0) return m_nums[right];

            return m_nums[right] - m_nums[left - 1];
        }

    private:
        std::vector<int> m_nums;
    };
}
