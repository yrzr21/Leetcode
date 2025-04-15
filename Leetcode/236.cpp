#include "../tools.h"

class Solution {
   public:
    // pq在root的两个子树中，或pq为root且另一者在子树中，则答案为root
    // pq在同一子树中，则查看该子树
    // 极端情形：root为空、root无孩子、root左右子树中均无pq
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (root == nullptr) return nullptr;
        if (root->left == nullptr && root->right == nullptr) return nullptr;

        bool in_left = find_p_or_q(root->left, p, q);
        bool in_right = find_p_or_q(root->right, p, q);

        if (p == root) {
            if (in_left || in_right)
                return root;
            else
                return nullptr;
        } else if (q == root) {
            if (in_left || in_right)
                return root;
            else
                return nullptr;
        }

        if (in_left && in_right)
            return root;
        else if (in_left && !in_right)
            return lowestCommonAncestor(root->left, p, q);
        else if (!in_left && in_right)
            return lowestCommonAncestor(root->right, p, q);
        else
            return nullptr;  // 左右均无
    }

   private:
    bool find_p_or_q(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (root == nullptr) return false;
        if (root == p || root == q) return true;
        return find_p_or_q(root->left, p, q) || find_p_or_q(root->right, p, q);
    }
};
int main(int argc, char const* argv[]) {
    return 0;
}
