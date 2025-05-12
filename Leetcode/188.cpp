#include "../tools.h"

class Solution {
   public:
    int maxProfit(int k, vector<int>& prices) {
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

        // 对于k笔交易，共有1+2k个状态
        // j为奇数，则可卖出，j为偶数，则可买入
        n = prices.size();
        this->k = k;
        dp = vector<vector<int>>(n, vector<int>(1 + 2 * k, -1));

        return maxProfitIJ(prices, 0, 0);
    }

   private:
    int n, k;
    vector<vector<int>> dp;

    int maxProfitIJ(vector<int>& prices, int i, int j) {
        if (i == n || j == 2 * k + 1) return 0;
        if (dp[i][j] != -1) return dp[i][j];

        int plus = (j % 2 == 0 ? -prices[i] : prices[i]);
        dp[i][j] = max(plus + maxProfitIJ(prices, i + 1, j + 1),
                       maxProfitIJ(prices, i + 1, j));

        return dp[i][j];
    }
};

int main(int argc, char const* argv[]) { return 0; }
