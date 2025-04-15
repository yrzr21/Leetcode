#include "../tools.h"

class Solution {
   public:
    // 遍历一遍，记录所有数字，排序，再遍历一遍计算
    // 潜在加速可能：遇到一样的直接返回0
    // 以上是非二叉搜索树的做法，对于二叉搜索树：最小差值为前驱和后继中最小的
    int getMinimumDifference(TreeNode* root) {
        dfs(root);
        return min_dif;
    }

   private:
    int min_dif = 100001;
    int pre = -1;

    void dfs(TreeNode* root) {
        if (root == nullptr) return;
        dfs(root->left);

        if (pre != -1) {
            min_dif = min(abs(root->val - pre), min_dif);
        }
        pre = root->val;

        dfs(root->right);
    }
};
int main(int argc, char const* argv[]) {
    return 0;
}
