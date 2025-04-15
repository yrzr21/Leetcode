#include "../tools.h"

class Solution {
   public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        return isSubSymmetric(root->left, root->right);
    }

   private:
    bool isSubSymmetric(TreeNode* left, TreeNode* right) {
        if (left == nullptr && right == nullptr) return true;
        if (left == nullptr ^ right == nullptr) return false;
        if (left->val != right->val) return false;

        return isSubSymmetric(left->left, right->right) &&
               isSubSymmetric(left->right, right->left);
    }
};

int main(int argc, char const* argv[]) { return 0; }
