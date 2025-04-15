#include "../tools.h"

class Solution {
   public:
    TreeNode *invertTree(TreeNode *root) {
        if (root == nullptr) return nullptr;

        TreeNode *tmp = root->left;
        root->left = invertTree(root->right);
        root->right = invertTree(tmp);
        return root;
    }
};

int main(int argc, char const *argv[]) { return 0; }
