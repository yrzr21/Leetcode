#include "../tools.h"

class Solution {
   public:
    int rob(vector<int>& nums) {
        n = nums.size();
        dp = vector<int>(n, -1);
        return robI(nums, 0);
    }

   private:
    vector<int> dp;  // dp[i] = max(nums[i]+dp[i+2], dp[i+1])
    int n;

    // 从i开始偷
    int robI(vector<int>& nums, int i) {
        if (i >= n) return 0;
        if (dp[i] != -1) return dp[i];

        dp[i] = max(nums[i] + robI(nums, i + 2), robI(nums, i + 1));
        return dp[i];
    }
};

// 迭代
class Solution2 {
   public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        // dp[i] = max(nums[i]+dp[i+2], dp[i+1])

        int cnt_1 = nums[n - 1], cnt_2 = 0;  // dp[i+1]、dp[i+2]
        int cnt_n;                           // dp[i]
        for (int i = n - 2; i >= 0; i--) {
            cnt_n = max(nums[i] + cnt_2, cnt_1);

            cnt_2 = cnt_1;
            cnt_1 = cnt_n;
        }
        return cnt_n;
    }
};

int main(int argc, char const* argv[]) { return 0; }
