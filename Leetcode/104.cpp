#include "../tools.h"

class Solution {
   public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};

int main(int argc, char const* argv[]) { return 0; }
