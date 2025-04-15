#include "../tools.h"

class Solution {
   public:
    // 每个深度一个节点，或许需要遍历所有节点
    vector<int> rightSideView(TreeNode* root) {
        dfs(0, root);
        return ans;
    }

   private:
    vector<int> ans;  // ans[i]表示depth i所见的view

    // depth 从0开始
    void dfs(int depth, TreeNode* root) {
        if (root == nullptr) return;
        // ans[ans.size()] 表示下一个位置
        if (ans.size() == depth) ans.push_back(root->val);

        dfs(depth + 1, root->right);
        dfs(depth + 1, root->left);
    }
};

int main(int argc, char const* argv[]) { return 0; }
