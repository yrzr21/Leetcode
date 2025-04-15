#include "../tools.h"

class Solution {
   public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (size_t i = 0; i < inorder.size(); i++) map[inorder[i]] = i;
        return buildSubTree(preorder, inorder, preorder.size());
    }

   public:
    int i = 0, j = 0;
    unordered_map<int, int> map;  // val,inorder_index
    // preorder[i] = 子树的根，inorder[j]为最左端节点
    // pre: 根，左，右
    // in：左，根，右
    TreeNode* buildSubTree(vector<int>& preorder, vector<int>& inorder,
                           int count_subtree) {
        // i一定领先于j，所以不用判断j
        if (i >= preorder.size()) return nullptr;
        TreeNode* root = new TreeNode(preorder[i++]);

        // 非左下角，查看左子树
        int count_left = map[root->val] - j;
        if (count_left != 0) {
            root->left = buildSubTree(preorder, inorder, count_left);
        }
        // 此时必有 in[j] == root
        j++;
        // 此时 in[j] 为右子树最左下角，或没有右子树

        // 如何判断此处没有右子树，直接进入上一层级？哈希表记录
        int count_right = count_subtree - count_left - 1;
        if (count_right != 0) {
            root->right = buildSubTree(preorder, inorder, count_right);
        }
        return root;
    }
};

int main(int argc, char const* argv[]) { return 0; }
