#include "../tools.h"

class Solution {
   public:
    int coinChange(vector<int>& coins, int amount) {
        // 优先选取面额较大的硬币...但似乎没说要硬币面额是否有序？
        // dp[i]表示凑出 i，所需的最少硬币数
        // dp[i] = 1+ min(dp[i-coins[j]])
        dp = vector<int>(amount + 1, INT32_MAX);
        dp[0] = 0;

        return coinChangeI(coins, amount);
    }

   private:
    vector<int> dp;  // INT32_MAX未计算，-1无法凑成，>=可

    int coinChangeI(vector<int>& coins, int amount) {
        if (amount < 0) return -1;
        if (dp[amount] != INT32_MAX) return dp[amount];

        for (int coin : coins) {
            int cnt = coinChangeI(coins, amount - coin);

            if (cnt >= 0 && cnt + 1 < dp[amount]) {
                dp[amount] = cnt + 1;
            }
        }

        if (dp[amount] == INT32_MAX) dp[amount] = -1;
        return dp[amount];
    }
};

// 迭代
class Solution2 {
   public:
    int coinChange(vector<int>& coins, int amount) {
        // 优先选取面额较大的硬币...但似乎没说要硬币面额是否有序？
        // dp[i]表示凑出 i，所需的最少硬币数
        // dp[i] = 1+ min(dp[i-coins[j]])
        vector<int> dp(amount + 1, INT32_MAX);
        dp[0] = 0;

        int cur = 0;
        for (int coin : coins) {
        }
    }
};

int main(int argc, char const* argv[]) { return 0; }
