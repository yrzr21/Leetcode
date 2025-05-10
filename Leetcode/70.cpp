#include "../tools.h"

class Solution {
   public:
    // dp[n] = dp[n-1]+dp[n-2]
    int climbStairs(int n) {
        dp = vector<int>(n + 1, -1);
        // 提前计算 base case
        dp[1] = 1;
        if (n > 1) dp[2] = 2;

        return climb(n);
    }

   private:
    vector<int> dp;

    int climb(int n) {
        if (dp[n] != -1) return dp[n];

        dp[n] = climb(n - 1) + climb(n - 2);
        return dp[n];
    }
};

// 迭代
class Solution2 {
   public:
    int climbStairs(int n) {
        if (n <= 2) return n;
        int cnt_1 = 2, cnt_2 = 1;  // dp[n-1]、dp[n-2]
        int cnt_n;
        for (size_t i = 3; i <= n; i++) {
            cnt_n = cnt_1 + cnt_2;

            cnt_2 = cnt_1;
            cnt_1 = cnt_n;
        }

        return cnt_n;
    }
};

int main(int argc, char const *argv[]) { return 0; }
