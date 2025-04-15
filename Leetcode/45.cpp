#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int jump(vector<int> &nums) {
        if (nums.size() == 1) return 0;
        vector<int> dp(nums.size(), INT32_MAX);
        dp[nums.size() - 1] = 0;

        for (int i = nums.size() - 2; i >= 0; i--) {
            if (i + nums[i] >= nums.size() - 1) {
                dp[i] = 1;
                continue;
            }

            int minJump = INT32_MAX;  // 不能直接跳到，至少需要间接跳一次
            for (int j = 1; i + j < nums.size() && j <= nums[i]; j++) {
                if (dp[i + j] == INT32_MAX) continue;
                minJump = min(dp[i + j], minJump);
                if (minJump == 1) break;
            }
            if (minJump != INT32_MAX) dp[i] = 1 + minJump;
        }

        return dp[0];
    }
};

class Solution2 {
   public:
    int jump(vector<int> &nums) {
        if (nums.size() == 1) return 0;
        // 题目保证能抵达，所以这个条件始终为假
        if (nums[0] == 0) return -1;

        int cnt = 0, i = 0, start = 0;
        while (i < nums.size() - 1) {
            if (nums[i] == 0) {  // 无法抵达更远处
                i--;
                if (i == start) cnt--;
                continue;
            } else if (i + nums[i] >= nums.size() - 1)  // 可以直接跳到终点
                return cnt + 1;

            // 跳到能抵达最远处的下标
            start = i;
            int maxReach = 0, maxJ;
            for (int j = 1; j <= nums[i]; j++) {
                if (j + nums[i + j] <= maxReach) continue;
                maxReach = j + nums[i + j];
                maxJ = j;
            }
            i += maxJ;
            cnt++;
        }
        return cnt;
    }
};

int main(int argc, char const* argv[]) { return 0; }
