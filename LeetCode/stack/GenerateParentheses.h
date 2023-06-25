#pragma once
#include <vector>
#include <string>

namespace
{
    void generate(int n, int opened, int closed, std::vector<std::string> &res, std::string str)
    {
        if (opened == closed && opened == n)
        {
            res.push_back(std::move(str));
            return;
        }

        if (opened < n)
        {
            generate(n, opened + 1, closed, res, str + '(');
        }

        if (closed < opened)
        {
            generate(n, opened, closed + 1, res, std::move(str) + ')');
        }
    }
}

namespace stack
{
    

    std::vector<std::string> generateParenthesis(int n)
    {
        std::vector<std::string> res;
        generate(n, 0, 0, res, "");

        return res;
    }
    
}