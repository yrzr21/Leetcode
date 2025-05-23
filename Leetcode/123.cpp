#include "../tools.h"

class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        // 每一天可以进行选择：若持有，可选择卖出、或不做任何操作；未持有，可选择买入，或不进行任何操作
        // dp[i][j]
        // 表示在第i天处于状态j时，所能获得的最大收益，状态j指上一天延续下来的状态
        // j：0未初始化，1第一次持有，2第一次卖出且未持有，3第二次持有，4第二次持有并卖出
        // 求dp[0][0]
        // dp[i][0]=max(-prices[i]+dp[i+1][1], dp[i+1][0])
        // dp[i][1]=max(prices[i]+dp[i+1][2], dp[i+1][1])
        // dp[i][2]=max(-prices[i]+dp[i+1][3], dp[i+1][2])
        // dp[i][3]=max(prices[i], dp[i+1][3])
        // 若i>n，则返回0

        n = prices.size();
        dp = vector<vector<int>>(n, vector<int>(4, -1));

        return maxProfitIJ(prices, 0, 0);
    }

   private:
    int n;
    vector<vector<int>> dp;

    int maxProfitIJ(vector<int>& prices, int i, int j) {
        if (i == n) return 0;
        if (dp[i][j] != -1) return dp[i][j];

        if (j == 0) {
            dp[i][j] = max(-prices[i] + maxProfitIJ(prices, i + 1, 1),
                           maxProfitIJ(prices, i + 1, 0));

        } else if (j == 1) {
            dp[i][j] = max(prices[i] + maxProfitIJ(prices, i + 1, 2),
                           maxProfitIJ(prices, i + 1, 1));
        } else if (j == 2) {
            dp[i][j] = max(-prices[i] + maxProfitIJ(prices, i + 1, 3),
                           maxProfitIJ(prices, i + 1, 2));
        } else {
            dp[i][j] = max(prices[i], maxProfitIJ(prices, i + 1, 3));
        }

        return dp[i][j];
    }
};

int main(int argc, char const* argv[]) { return 0; }
