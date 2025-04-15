#include "../tools.h"

class BSTIterator {
   public:
    BSTIterator(TreeNode* root) : cur(root) {}

    int next() {
        while (cur != nullptr) {
            parents.push(cur);
            cur = cur->left;
        }
        cur = parents.top();
        int ret = cur->val;
        parents.pop();
        cur = cur->right;
        return ret;
    }

    bool hasNext() { return !parents.empty() || cur != nullptr; }

   private:
    stack<TreeNode*> parents;
    TreeNode* cur;  // 当前子树
};

int main(int argc, char const* argv[]) { return 0; }
