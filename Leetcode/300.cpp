#include "../tools.h"

class Solution {
   public:
    // base case：n==1，return 1
    // dp[i] 截止index i开始的LIS
    // dp[i] = max(dp[0...i-1])+1
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        dp = vector<int>(n, -1);
        dp[0] = 1;

        for (int i = 1; i < n; i++) {
            lengthOfLISI(nums, i);
        }
        return ans;
    }

   private:
    vector<int> dp;  // -1未初始化
    int ans = 1;

    int lengthOfLISI(vector<int>& nums, int i) {
        if (dp[i] != -1) return dp[i];

        int max_sub = 0;
        for (size_t j = 0; j < i; j++) {
            if (nums[i] <= nums[j]) continue;
            max_sub = max(max_sub, lengthOfLISI(nums, j));
        }
        dp[i] = max_sub + 1;
        ans = max(ans, dp[i]);

        return dp[i];
    }
};

int main(int argc, char const* argv[]) { return 0; }
