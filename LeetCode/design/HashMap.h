#pragma once
#include <vector>

namespace design
{
    class MyHashMap {
    public:
        MyHashMap() 
            : m_data(100, -1)
        { }

        void put(int key, int value) 
        {
            if (key >= m_data.size())
                m_data.resize(key + 1, -1);
            m_data[key] = value;
        }

        int get(int key) 
        {
            if (key < m_data.size())
                return m_data[key];

            return -1;
        }

        void remove(int key) 
        {
            if (key < m_data.size())
                m_data[key] = -1;
        }

    private:
        std::vector<int> m_data;
    };
}
