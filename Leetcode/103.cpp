#include "../tools.h"

class Solution {
   public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == nullptr) return {};
        bool l2r = true;
        vector<vector<int>> ans;

        deque<TreeNode*> q;
        q.push_front(root);
        while (!q.empty()) {
            if (l2r) {
                l2r = false;
                ans.emplace_back(extract_l2r(q));
            } else {
                l2r = true;
                ans.emplace_back(extract_r2l(q));
            }
        }
        return ans;
    }

   private:
    vector<int> extract_l2r(deque<TreeNode*>& q) {
        int n = q.size();
        vector<int> tmp;

        for (size_t i = 0; i < n; i++) {
            TreeNode* node = q.front();
            q.pop_front();
            tmp.push_back(node->val);
            if (node->left != nullptr) q.push_back(node->left);
            if (node->right != nullptr) q.push_back(node->right);
        }

        return tmp;
    }

    vector<int> extract_r2l(deque<TreeNode*>& q) {
        int n = q.size();
        vector<int> tmp;

        for (size_t i = 0; i < n; i++) {
            TreeNode* node = q.back();
            q.pop_back();
            tmp.push_back(node->val);
            if (node->right != nullptr) q.push_front(node->right);
            if (node->left != nullptr) q.push_front(node->left);
        }

        return tmp;
    }
};
int main(int argc, char const* argv[]) {
    return 0;
}
