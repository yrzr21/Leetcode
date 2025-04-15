#include "../tools.h"

class Solution {
   public:
    // 返回root子树的最大路径和
    // 最终的结果一定是一条路径，即考虑某个根节点的值
    int maxPathSum(TreeNode* root) {
        maxSubPathSum(root);
        return maxSum;
    }

   private:
    int maxSum = INT32_MIN;
    // unordered_map<TreeNode*, int> map;  // 从该节点到叶的最大路径

    // 返回从该节点往下单向行走的最大值
    // int maxLeafPathSum(TreeNode* root) {
    //     if (root == nullptr) return 0;
    //     if (map.find(root) != map.end()) return map[root];

    //     int left = maxLeafPathSum(root->left);
    //     int right = maxLeafPathSum(root->right);
    //     int max_child = max(left, right) <= 0 ? 0 : max(left, right);

    //     map[root] = max_child + root->val;
    //     return map[root];
    // }

    // 只要左右子路径和大于0，就纳入考虑，因此上述的map是不必要的
    // 经过root
    int maxSubPathSum(TreeNode* root) {
        if (root == nullptr) return 0;
        // 以root为根
        int result = root->val;
        int left = maxSubPathSum(root->left);
        if (left > 0) result += left;

        int right = maxSubPathSum(root->right);
        if (right > 0) result += right;
        if (result > maxSum) maxSum = result;

        return root->val + max(max(left, right), 0);
    }
};

int main(int argc, char const* argv[]) { return 0; }
