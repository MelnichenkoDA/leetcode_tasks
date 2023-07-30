#pragma once
#include <vector>

namespace design
{
    class MyHashSet {
    public:
        MyHashSet() 
            : m_data(100)
        { }

        void add(int key) 
        {
            if (key < m_data.size())
                m_data[key] = 1;
            else
            {
                m_data.resize(key + 1);
                m_data[key] = 1;
            }
        }

        void remove(int key) 
        {
            if (contains(key))
                m_data[key] = 0;
        }

        bool contains(int key) 
        {
            return key < m_data.size() && m_data[key];
        }

    private:
        std::vector<int> m_data;
    };
}