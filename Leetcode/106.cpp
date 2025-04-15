#include "../tools.h"

class Solution {
   public:
    // in: 左，根，右
    // post：左，右，根
    // 倒着来似乎比较顺
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (size_t i = 0; i < inorder.size(); i++) map[inorder[i]] = i;
        j = inorder.size() - 1;
        i = inorder.size() - 1;

        return buildSubTree(inorder, postorder, inorder.size());
    }

   private:
    unordered_map<int, int> map;  // in_val,in_idnex
    int i, j;                     // in, post
    TreeNode* buildSubTree(vector<int>& inorder, vector<int>& postorder,
                           int subtree_count) {
        cout << "i=" << i << ",j=" << j <<", subtree_count="<<subtree_count<< endl;
        if (subtree_count == 0) return nullptr;  // 保证了 ij 不越界？
        TreeNode* root = new TreeNode(postorder[j--]);

        int right_count = i - map[root->val];
        int left_count = subtree_count - right_count - 1;
        cout << "root=" << root->val << ", ";
        cout << "left_count=" << left_count << ",right_count=" << right_count
             << endl;

        root->left = buildSubTree(inorder, postorder, left_count);
        i++;
        root->right = buildSubTree(inorder, postorder, right_count);
        return root;
    }
};

int main(int argc, char const* argv[]) { return 0; }
