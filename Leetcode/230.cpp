#include "../tools.h"
class Solution {
   public:
    int kthSmallest(TreeNode* root, int k) {
        this->k = k;
        dfs(root);
        return ans;
    }

   private:
    int no = 1;  // 当前元素的序号
    int k;
    int ans;
    void dfs(TreeNode* root) {
        if (root == nullptr) return;
        if (k < 0) return; // 终止

        dfs(root->left);
        cout << "no=" << no << ",root=" << root->val << endl;
        if (no == k) {
            ans = root->val;
            k = -1;
            return;
        }
        no++;
        dfs(root->right);
    }
};
int main(int argc, char const* argv[]) {
    return 0;
}
