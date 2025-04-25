#include "../tools.h"

class Solution {
   public:
    int maxSubarraySumCircular(vector<int>& nums) {
        // maxSubArray 要么跨环，要么不跨越
        // 对于2，采用原先解法即可
        // 对于1，total-minSubArray即可

        int maxCur = nums[0];  // dp[i-1]
        int maxSub = nums[0];

        int minCur = nums[0];
        int minSub = nums[0];

        int total = nums[0];
        for (size_t i = 1; i < nums.size(); i++) {
            if (maxCur < 0) maxCur = 0;
            maxCur += nums[i];
            if (maxCur > maxSub) maxSub = maxCur;

            if (minCur > 0) minCur = 0;
            minCur += nums[i];
            if (minCur < minSub) minSub = minCur;

            total += nums[i];
        }

        if (maxSub <= 0)  // 全负数
            return maxSub;
        else
            return max(maxSub, total - minSub);
    }
};

int main(int argc, char const* argv[]) {
    vector<int> nums{-3, -2, -3};
    Solution().maxSubarraySumCircular(nums);

    return 0;
}
