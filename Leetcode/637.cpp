#include "../tools.h"

class Solution {
   public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int n = q.size();
            long cnt = 0;
            for (size_t i = 0; i < n; i++) {
                TreeNode* node = q.front();
                cnt += node->val;
                q.pop();

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            ans.push_back(1.0 * cnt / n);
        }
        return ans;
    }
};

int main(int argc, char const* argv[]) { return 0; }
