#include "../tools.h"

class Solution {
   public:
    vector<vector<int>> permute(vector<int>& nums) {
        backtrack(0, nums);

        return ans;
    }

   private:
    vector<vector<int>> ans;

    // i 表示待选择的位置的index，也表示已选择的个数
    void backtrack(int i, vector<int>& nums) {
        // 最后一个无需再遍历
        if (i == nums.size() - 1) {
            ans.push_back(nums);
            return;
        }

        for (size_t j = i; j < nums.size(); j++) {
            swap(nums[i], nums[j]);
            backtrack(i + 1, nums);
            swap(nums[i], nums[j]);
        }
    }
};

int main(int argc, char const* argv[]) {
    vector<int> v{1, 2, 3};
    Solution().permute(v);
    return 0;
}
