#include "../tools.h"

class Solution {
   public:
    int maxSubArray(vector<int>& nums) {
        // dp[i]：以nums[i]结尾的maxSubArray
        // dp[i] = max(dp[i-1]+nums[i], nums[i])，当且仅当 dp[i-1] <= 0 选择后者
        int ans = nums[0];
        int cur = 0;  // dp[i-1]
        for (size_t i = 0; i < nums.size(); i++) {
            if (cur < 0) cur = 0;
            cur += nums[i];

            if (ans < cur) ans = cur;
        }

        return ans;
    }
};

int main(int argc, char const* argv[]) { return 0; }
