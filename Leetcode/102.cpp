#include "../tools.h"
class Solution {
   public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            vector<int> tmp;
            for (size_t i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();
                tmp.push_back(node->val);
                if (node->left != nullptr) q.push(node->left);
                if (node->right != nullptr) q.push(node->right);
            }
            ans.emplace_back(move(tmp));
        }
        return ans;
    }
};

int main(int argc, char const* argv[]) { return 0; }
