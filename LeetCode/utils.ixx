#include <vector>

export module utils;

export 
namespace utils
{
    template<typename T>
	bool compare(std::vector<T> const& first, std::vector<T> const& second)
    {
        for (auto num : first)
        {
            if (std::find(second.cbegin(), second.cend(), num) == second.cend())
                return false;
        }

        return true;
    }
}