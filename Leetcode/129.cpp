#include "../tools.h"

class Solution {
   public:
    int sumNumbers(TreeNode* root) {
        subSum(root, 0);
        return total;
    }

   private:
    int total = 0;
    // cnt*10+root->val
    void subSum(TreeNode* root, int cnt) {
        if (root == nullptr) return;
        cnt = cnt * 10 + root->val;

        if (root->left == nullptr && root->right == nullptr) {
            total += cnt;
            return;
        }

        subSum(root->left, cnt);
        subSum(root->right, cnt);
    }
};

int main(int argc, char const* argv[]) { return 0; }
