#include <vector>
#include <unordered_map>

namespace math
{
    void setZeroes(std::vector<std::vector<int>>& matrix)
    {
        std::unordered_map<int, std::vector<int>> zeroes;

        for (int i = 0; i < matrix.size(); ++i)
        {
            for (int j = 0; j < matrix[i].size(); ++j)
            {
                if (matrix[i][j] == 0)
                {
                    zeroes[i].push_back(j);
                }
            }
        }

        for (auto &[row, cols] : zeroes)
        {
            for (int i = 0; i < matrix[row].size(); ++i)
                matrix[row][i] = 0;

            for (auto col : cols)
            {
                for (int i = 0; i < matrix.size(); ++i)
                    matrix[i][col] = 0;
            }
        }
    }
}