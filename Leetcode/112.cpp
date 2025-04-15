#include "../tools.h"

class Solution {
   public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return false;
        if (root->left == nullptr && root->right == nullptr)
            return targetSum == 0;
        if (targetSum <= 0) return false;
        

        return hasPathSum(root->left, targetSum - root->val) |
               hasPathSum(root->right, targetSum - root->val);
    }
};

int main(int argc, char const* argv[]) { return 0; }
