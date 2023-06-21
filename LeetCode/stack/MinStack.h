#pragma once
#include <vector>

namespace stack
{
    class MinStack {
    public:
        MinStack() 
        { }

        void push(int val) 
        {
            if (!m_data.empty())
            {
                m_data.emplace_back(val, val < m_data.back().second ? val : m_data.back().second);
            }
            else
            {
                m_data.emplace_back(val, val);
            }
        }

        void pop() 
        {
            m_data.pop_back();
        }

        int top() 
        {
            return m_data.back().first;
        }

        int getMin() 
        {
            return m_data.back().second;
        }

    private:
        std::vector<std::pair<int, int>> m_data;
    };
}
