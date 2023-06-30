#pragma once
#include <string>

namespace two_pointers
{
    bool isPalindrome(std::string str) 
    {
        int left = 0;
        auto right = str.size() - 1;

        while (left < right)
        {
            if (!std::isalnum(str[left]))
            {
                ++left;
                continue;
            }

            if (!std::isalnum(str[right]))
            { 
                --right;
                continue;
            }

            if (str[left] != str[right])
            {
                if (std::isdigit(str[left]) || (str[left] + 32 != str[right] && str[left] - 32 != str[right]))
                    return false;
            }

            ++left;
            --right;
        }

        return true;
    }
}
