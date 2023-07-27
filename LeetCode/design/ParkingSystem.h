#include <array>

namespace design
{
    class ParkingSystem {
    public:
        ParkingSystem(int big, int medium, int small) 
            : m_slots{ std::pair{0,0}, std::pair{0,big}, std::pair{0,medium}, std::pair{0,small} }
        { 
        }

        bool addCar(int carType) 
        {
            return (++m_slots[carType].first <= m_slots[carType].second);
        }

    private:
        std::array<std::pair<int, int>, 4> m_slots;
    };
}


