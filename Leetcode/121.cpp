#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int profit = 0, minPrice = 10001;
        for (int price : prices)
        {
            if (price < minPrice) // 买入
                minPrice = price;
            else if (profit < price - minPrice) // 考虑卖出
                profit = price - minPrice;
        }
        return profit;
    }
};
int main(int argc, char const* argv[]) {
    return 0;
}
