#pragma once
#include <vector>


namespace stack
{
    std::vector<int> dailyTemperatures(std::vector<int> const& temperatures) 
    {
        std::vector<int> res(temperatures.size(), 0);
        std::vector<std::pair<int, int>> temp;

        for (int i = 1; i < temperatures.size(); ++i)
        {
            auto const curInd = i - 1;
            if (temperatures[curInd] < temperatures[i])
            {
                res[curInd] = 1;
                while (!temp.empty() && temp.back().first < temperatures[i])
                {
                    res[temp.back().second] = i - temp.back().second;
                    temp.pop_back();
                }
            }
            else
            {
                temp.emplace_back(temperatures[curInd], curInd);
            }
        }

        return res;
    }
}