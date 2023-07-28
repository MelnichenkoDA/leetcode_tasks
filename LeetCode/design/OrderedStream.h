#include <vector>
#include <string>

namespace design
{
    class OrderedStream {
    public:
        OrderedStream(int n)
            : m_data(n + 1)
        {
        }

        std::vector<std::string> insert(int idKey, std::string value) 
        {
            m_data[idKey] = std::move(value);
            std::vector<std::string> res;

            if (idKey == m_curr)
            {
                while (idKey < m_data.size())
                {
                    if (m_data[idKey].empty())
                        break;

                    ++idKey;
                }
                res = std::vector(m_data.begin() + m_curr, m_data.begin() + idKey);
                m_curr = idKey;
            }

            return res;
        }

    private:
        std::vector<std::string> m_data;
        int m_curr{1};
    };
}
