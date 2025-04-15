#include "../tools.h"

class Solution {
   public:
    // 二分
    // 1.先遍历到底部查看高度
    // 2.二分：搜索左子树的最右边，查看是否有节点，若有，则节点数至少为满二叉树的左子树+1+右子树节点数
    int countNodes(TreeNode* root) {
        if (root == nullptr) return 0;
        int cnt = 0;
        int height = getHeight(root);
        while (root != nullptr) {
            cout << "height=" << height << " ,";
            cnt++;  // root
            if (root->left == nullptr) return cnt;
            // 高度至少为1
            if (is_full(root->left, height - 1)) {
                cout << "left full, ";
                cnt += count(height - 1);  // left
                root = root->right;
            } else {
                cout << "left not full, ";
                root = root->left;
                cnt += count(height - 2);  // right
            }
            cout << "cnt=" << cnt << endl;

            height--;
        }

        return cnt;
    }

   private:
    // 满二叉树的节点数，height从0开始，-1表示空树
    int count(int height) { return (1 << (height + 1)) - 1; }

    // 计算完全二叉树的高度
    int getHeight(TreeNode* root) {
        if (root == nullptr) return 0;
        int cnt = 0;
        while (root->left != nullptr) {
            root = root->left;
            cnt++;
        }
        return cnt;
    }

    // 输入一颗完全二叉树及其高度，返回是否是满的
    bool is_full(TreeNode* root, int height) {
        if (height == 0 || height == -1) return true;
        while (root->right != nullptr) {
            height--;
            root = root->right;
        }
        return height == 0;
    }
};

int main(int argc, char const* argv[]) { return 0; }
