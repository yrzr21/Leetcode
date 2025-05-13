#include <algorithm>
#include <iostream>
#include <unordered_set>
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

// 复习1
class Solution1 {
   public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        // 拿到一个数nums[i]作为target，查看后面的数组中有没有和等于它的
        // set存所有数字，加速查找
        // 避免重复？ 排个序，然后看看重复的在不在
        unordered_set<int> set;
        for (int num : nums) {
            set.insert(num);
        }
        sort(nums.begin(), nums.end());


        vector<vector<int>> ans;
        for (size_t i = 0; i < nums.size(); i++) {
            int index = i;
            int neg_target = nums[i];  // target=-nums[i]
            while (nums[i] == neg_target) i++;
            int n_same = i - index;

            if(n_same>=3 && an) 


        }
    }
};

int main(int argc, char const *argv[]) {
    vector<int> v{-1, 0, 1, 2, -1, -4};
    Solution().threeSum(v);
    return 0;
}
