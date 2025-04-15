#include "../tools.h"

class Solution {
   public:
    void flatten(TreeNode* root) {
        if (root != nullptr) flattenSub(root);
    }

   private:
    // 将root为根的二叉树变为要求的形式，返回末尾的节点
    TreeNode* flattenSub(TreeNode* root) {
        if (root->left == nullptr && root->right == nullptr) return root;

        TreeNode* last = nullptr;
        TreeNode* right = root->right;

        if (root->left != nullptr) {
            // 加入到右边，flattern，插入右子节点到最后
            root->right = root->left;
            root->left = nullptr;
            last = flattenSub(root->right);

            last->right = right;
        }

        // flattern 右子节点
        if (right != nullptr) last = flattenSub(right);
        return last;
    }
};
int main(int argc, char const* argv[]) { return 0; }
