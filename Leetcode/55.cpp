#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// dp
class Solution {
   public:
    bool canJump(vector<int> &nums) {
        if (nums.size() == 1) return true;

        vector<bool> dp(nums.size(), false);
        int dest = nums.size() - 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (nums[i] + i >= dest) {
                dp[i] = true;
                continue;
            }

            for (int j = 1; j <= nums[i] && i + j < nums.size(); j++) {
                if (!dp[i + j]) continue;
                dp[i] = true;
                break;
            }
        }

        return dp[0];
    }
};

// 一次遍历即可
class Solution2 {
   public:
    bool canJump(vector<int> &nums) {
        if (nums.size() == 1) return true;

        int reach = 0;
        for (size_t i = 0; i < nums.size(); i++) {
            if (nums[i] + i > reach) reach = nums[i] + i;
            if (reach >= nums.size() - 1) return true;
            if (i == reach) return false;
        }

        // 这里应该不可能抵达
        return false;
    }
};
int main(int argc, char const* argv[]) {
    return 0;
}
