#include <string>
#include <unordered_set>

namespace sliding_window
{
    int lengthOfLongestSubstring(std::string str) 
    {
        int res{};
        std::unordered_set<char> set;

        for (int i = 0; i < str.size(); ++i)
        {
            if (auto const [_, inserted] = set.insert(str[i]); !inserted)
            {
                res = std::max(res, static_cast<int>(set.size()));
                i -= static_cast<int>(set.size());
                set.clear();
            }
        }

        return std::max(res, static_cast<int>(set.size()));
    }
}