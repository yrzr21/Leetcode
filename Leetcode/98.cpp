#include "../tools.h"

class Solution {
   public:
    bool isValidBST(TreeNode* root) {
        dfs(root);
        return is_bst;
    }

   private:
    long pre = INT64_MIN;
    int is_bst = true;

    void dfs(TreeNode* root) {
        if (root == nullptr) return;
        if (!is_bst) return;

        dfs(root->left);
        if (pre != INT64_MIN && pre >= root->val) is_bst = false;
        pre = root->val;
        dfs(root->right);
    }
};
int main(int argc, char const* argv[]) {
    return 0;
}
