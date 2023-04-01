export module BestTimeToBuyAndSell;

import <vector>;
import <assert.h>;
import <map>;

export namespace BestTimeToBuyAndSell
{
    int maxProfit(std::vector<int> const& prices)
    {
        int buy = prices[0], maxProfit{};
        for (int i = 1; i < prices.size(); ++i)
        {
            if (prices[i] < buy)
                buy = prices[i];
            else if (auto const currentProfit = prices[i] - buy; currentProfit > maxProfit)
                maxProfit = currentProfit;
        }

        return maxProfit;
    }

    void test()
    {
        assert(maxProfit({ 7,1,5,3,6,4 }) == 5);
        assert(maxProfit({ 7,6,4,3,1 }) == 0);
    }
}