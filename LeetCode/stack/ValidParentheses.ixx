export module ValidParentheses;

import <string>;
import <stack>;
import <assert.h>;

export namespace ValidParentheses
{
    bool isValid(std::string str) 
    {
        std::stack<char> parentheses;
        for (auto const ch : str)
        {
            if (ch == '(' || ch == '{' || ch == '[')
                parentheses.push(ch);
            else
            {
                if (parentheses.empty()) return false;

                if (ch == ')')
                {
                    if (auto const top = parentheses.top(); top != '(')
                        return false;
                }
                else if (ch == '}')
                {
                    if (auto const top = parentheses.top(); top != '{')
                        return false;
                }
                else if (ch == ']')
                {
                    if (auto const top = parentheses.top(); top != '[')
                        return false;
                }
                parentheses.pop();
            }
        }

        return parentheses.empty();
    }

    void test()
    {
        assert(isValid("()"));
        assert(isValid("[") == false);
        assert(isValid("]") == false);
        assert(isValid("()[]{}"));
        assert(isValid("([{{}}])"));
        assert(isValid("(]") == false);
    }
}