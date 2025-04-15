#include "../tools.h"

class Solution {
   public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) return true;
        if (p == nullptr ^ q == nullptr) return false;
        if (p->val != q->val) return false;

        // 子树
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

int main(int argc, char const* argv[]) { return 0; }
