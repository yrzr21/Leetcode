#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int i = 0;
        int size = nums.size();
        vector<vector<int>> ans;

        // 遍历第一个变量, 后面两数之和转换为双指针

        while (i != size - 2) {
            int target = -nums[i];
            // 两数之和
            int l = i + 1, r = size - 1;
            while (l < r) {
                if (nums[l] + nums[r] == target) {
                    ans.push_back({-target, nums[l], nums[r]});
                    // break?
                    // nums[l]==nums[r],必须break
                    // nums[l+1]==nums[l],跳过相等的,r同理
                    if (nums[l] == nums[r]) break;
                    int tmp = nums[l];
                    while (l < r && nums[l] == tmp) l++;
                } else if (nums[l] + nums[r] < target)
                    l++;
                else
                    r--;
            }

            // 跳过第一个变量重复的
            while (i != size - 2 && -nums[i] == target) i++;
        }
        return ans;
    }
};

int main(int argc, char const *argv[]) {
    vector<int> v{-1, 0, 1, 2, -1, -4};
    Solution().threeSum(v);
    return 0;
}
