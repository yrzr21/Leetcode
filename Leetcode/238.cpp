#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size(), 1);
        vector<int> L(nums.size(), 1);
        vector<int> R(nums.size(), 1);

        int tmp = nums[0];
        for (size_t i = 1; i < nums.size(); i++) {
            L[i] = tmp;
            tmp *= nums[i];
        }
        tmp = nums.back();
        for (size_t i = nums.size() - 2; i >= 0; i--) {
            R[i] = tmp;
            tmp *= nums[i];
        }

        for (size_t i = 0; i < nums.size(); i++) ans[i] = L[i] * R[i];

        return ans;
    }
};

// 更小的空间，稍微优化的时间
// 但复杂度无显著差异，仅常数项乘积不同
class Solution2 {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size(), 1);
        // 先计算L
        for (int i = 1; i < nums.size(); i++) {
            ans[i] = ans[i - 1] * nums[i - 1];
        }
        // 再计算R
        int tmp = nums.back();
        for (int i = nums.size() - 2; i >= 0; i--) {
            ans[i] *= tmp;
            tmp *= nums[i];
        }

        return ans;
    }
};
int main(int argc, char const* argv[]) {
    return 0;
}
