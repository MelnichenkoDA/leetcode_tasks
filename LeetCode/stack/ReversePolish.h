#pragma once
#include <vector>
#include <string>

namespace stack
{
    int evalRPN(std::vector<std::string> const& tokens) 
    {
        std::vector<int> values;
        for (auto const &token : tokens)
        {
            if (token.size() > 1 || std::isdigit(token[0]))
            {
                values.push_back(std::stoi(token));
                continue;
            }

            switch (token[0])
            {
            case '+':
            {
                int temp = values.back();
                values.pop_back();

                values.back() += temp;
                continue;
            }                
            case '-':
            {
                int temp = values.back();
                values.pop_back();

                values.back() -= temp;
                continue;
            }
            case '/':
            {
                int temp = values.back();
                values.pop_back();

                values.back() /= temp;
                continue;
            }
            case '*':
            {
                int temp = values.back();
                values.pop_back();

                values.back() *= temp;
                continue;
            }                
            }
        }

        return values.back();
    }
}
