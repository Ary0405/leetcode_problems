// Problem - 121 (Best Time to Buy and Sell Stock)
// Time Complexity - O(n)
// Space Complexity - O(1)

#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int> &prices)
{
    int currBuy = prices[0];
    int maxProf = 0;

    for (int i = 0; i < prices.size(); i++)
    {
        if (prices[i] > currBuy)
        {
            maxProf = max(maxProf, prices[i] - currBuy);
        }
        currBuy = min(prices[i], currBuy);
    }

    return maxProf;
}

int main()
{
    // can be completed
}