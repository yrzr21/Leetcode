#include "../tools.h"

class Solution {
   public:
    int subarraySum(vector<int>& nums, int k) {
        // 不能改变元素顺序
        // 朴素解法：枚举每个元素l为首元素，枚举后面每个元素r作为末尾，计算和是否等于k
        // 考虑优化？pre[i] = sum[0..i], 假设 sum[i..j]==k，则
        // pre[j]-pre[i-1]==k 求有多少个j，即求
        // pre[i-1]==pre[j]-k，即枚举j，计算前缀和-k，查看值是否在前缀和中

        unordered_map<int, int> pre_sum;  // 前缀和
        pre_sum.emplace(0, 1);

        int sum = 0;
        int ans = 0;
        for (size_t j = 0; j < nums.size(); j++) {
            sum += nums[j];
            if (auto iter = pre_sum.find(sum - k); iter != pre_sum.end())
                ans += iter->second;

            if (auto iter = pre_sum.find(sum); iter != pre_sum.end()) {
                iter->second++;
            } else {
                pre_sum.emplace(sum, 1);
            }
        }

        return ans;
    }
};

int main(int argc, char const* argv[]) { return 0; }
