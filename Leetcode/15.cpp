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
        // 拿到一个数nums[i]作为target，查看后面的数组中有没有和等于它的负的
        // set存所有数字，加速查找
        // 避免重复？ 排个序，按从小到大的顺序处理
        // 加速两数之和：set+枚举第二个数

        int n = nums.size();
        unordered_multiset<int> set;
        for (int num : nums) set.insert(num);

        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        if (set.count(0) >= 3) ans.push_back({0, 0, 0});

        for (size_t i = 0; i < n;) {
            // x<y<z
            int x = nums[i], x_cnt = set.count(x);  // min element
            if (x >= 0) break;
            // x<0

            if (x_cnt >= 2 && set.contains(-2 * x)) {
                // 2个x
                ans.push_back({x, x, -2 * x});
            }

            // 1个x
            for (int j = i + x_cnt; j < n;) {
                int y = nums[j], y_cnt = set.count(y);
                if (x + y >= 0) break;
                // x+y<0

                if (y > 0 && y_cnt >= 2 && x + y + y == 0) {
                    // 2个y：y必须大于0，与1个y的情形不兼容
                    ans.push_back({x, y, y});
                } else {
                    // 1个y
                    int z = -x - y;
                    if (z > y && set.contains(z)) ans.push_back({x, y, z});
                }

                j += y_cnt;
            }

            i += x_cnt;
        }

        return ans;
    }
};

class Solution2 {
   public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        // 拿到一个数nums[i]作为target，查看后面的数组中有没有和等于它的负的
        // 避免重复？ 排个序，按从小到大的顺序处理
        // x+y+z=0,
        // x<=y<=z，先确定x，只要y确定则z确定，为避免重复，每次找到ans都要跳过相等的y
        sort(nums.begin(), nums.end());

        int n = nums.size();

        vector<vector<int>> ans;
        for (size_t i = 0; i < n - 2;) {
            int x = nums[i];
            if (x > 0) break;

            int l = i + 1, r = n - 1;
            while (l < r) {
                int y = nums[l], z = nums[r];
                if (z < 0 || x + y + y > 0) break;

                if (x + y + z > 0) {
                    r--;
                } else if (x + y + z < 0) {
                    l++;
                } else {
                    ans.push_back({x, y, z});
                    while (l < r && nums[l] == y) l++;
                    while (l < r && nums[r] == z) r--;
                }
            }

            while (i < n - 2 && nums[i] == x) i++;
        }

        return ans;
    }
};

int main(int argc, char const *argv[]) {
    vector<int> v{-1, 0, 1, 2, -1, -4};
    Solution().threeSum(v);
    return 0;
}
