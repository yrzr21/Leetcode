#include <vector>
using namespace std;

class Node {
   public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {
        val = false;
        isLeaf = false;
        topLeft = nullptr;
        topRight = nullptr;
        bottomLeft = nullptr;
        bottomRight = nullptr;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = nullptr;
        topRight = nullptr;
        bottomLeft = nullptr;
        bottomRight = nullptr;
    }

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight,
         Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

// 非叶节点 val 无意义，可存储任意值

class Solution {
   public:
    Node* construct(vector<vector<int>>& grid) {
        return construct(grid, 0, grid.size() - 1, 0, grid.size() - 1);
    }

   private:
    // 四个int对应当前区域的四个边角 index
    // 返回构造好的根节点
    // 0..7
    // 0..3 + 4..7(4..5+6..7)

    Node* construct(vector<vector<int>>& grid, int top, int bottom, int left,
                    int right) {
        // leaf，有一对相等意味另外一对也相等
        if (top == bottom) return new Node(grid[top][left], true);

        Node* root = new Node;
        if (!is_leaf(grid, top, bottom, left, right)) {
            int mid_x = (left + right) / 2;
            int mid_y = (top + bottom) / 2;
            root->topLeft = construct(grid, top, mid_y, left, mid_x);
            root->topRight = construct(grid, top, mid_y, mid_x + 1, right);
            root->bottomLeft = construct(grid, mid_y + 1, bottom, left, mid_x);
            root->bottomRight =
                construct(grid, mid_y + 1, bottom, mid_x + 1, right);
        } else {
            root->val = grid[top][left];
            root->isLeaf = true;
        }
        return root;
    }

    bool is_leaf(vector<vector<int>>& grid, int top, int bottom, int left,
                 int right) {
        int origin = grid[top][left];
        for (size_t i = top; i <= bottom; i++) {
            for (size_t j = left; j <= right; j++) {
                if (grid[i][j] != origin) return false;
            }
        }
        return true;
    }
};

int main(int argc, char const* argv[]) {
    vector<vector<int>> v{{1, 1, 0, 0, 0, 0, 1, 1}, {1, 1, 0, 0, 0, 0, 1, 1},
                          {0, 0, 0, 0, 0, 0, 1, 1}, {0, 0, 0, 0, 0, 0, 1, 1},
                          {0, 0, 0, 0, 0, 0, 1, 1}, {0, 0, 0, 0, 0, 0, 1, 1},
                          {1, 1, 0, 0, 0, 0, 1, 1}, {1, 1, 0, 0, 0, 0, 1, 1}};
    Solution().construct(v);
    return 0;
}
