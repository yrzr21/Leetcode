#include "../tools.h"

class Solution {
   public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return arr2bst(nums, 0, nums.size());
    }

   private:
    // [l,r]为选取区间
    // 返回构建好的树根
    TreeNode* arr2bst(vector<int>& nums, int l, int r) {
        if (l > r) return nullptr;
        if (l == r) return new TreeNode(nums[l]);

        int root_index = (r + l) / 2;
        TreeNode* root = new TreeNode(nums[root_index]);
        root->left = arr2bst(nums, l, root_index - 1);
        root->right = arr2bst(nums, root_index + 1, r);
        return root;
    }
};

int main(int argc, char const* argv[]) { return 0; }
