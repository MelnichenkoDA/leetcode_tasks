#include <vector>
#include <assert.h>

export module GuessNumberHigherOrLower;

export namespace GuessNumberHigherOrLower
{
    class Guess
    {
    public:
        Guess(int i) : m_i(i) {}

        int guess(int i)
        {
            if (i == m_i) return 0;
            if (i < m_i) return 1;
            if (i > m_i) return -1;
        }

        int guessNumber(int n)
        {
            int left = 1;
            int right = n;
            while (left != right)
            {
                int currentGuess = left + (right - left) / 2;
                auto guessRes = guess(currentGuess);
                if (guessRes == 0)
                    return currentGuess;

                if (guessRes == -1)
                    right = currentGuess - 1;
                else
                    left = currentGuess + 1;
            }

            return left;
        }

        int m_i;
    };    

    void test()
    {
        assert(Guess(6).guessNumber(10) == 6);
        assert(Guess(1).guessNumber(10) == 1);
        assert(Guess(1).guessNumber(1) == 1);
        assert(Guess(1).guessNumber(2) == 1);
    }
}