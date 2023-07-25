#include <vector>

namespace math
{
    void rotate(std::vector<std::vector<int>>& matrix)
    {
        int const size = static_cast<int>(matrix.size());
        for (int i = 0; i < size; ++i)
        {
            for (int j = i + 1; j < size; ++j)
            {
                std::swap(matrix[i][j], matrix[j][i]);
            }
        }

        for (int i = 0; i < size / 2; ++i)
        {
            for (int j = 0; j < size; ++j)
            {
                std::swap(matrix[j][i], matrix[j][matrix.size() - 1 - i]);
            }
        }
    }
}