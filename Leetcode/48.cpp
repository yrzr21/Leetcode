#include <iostream>
#include <vector>
using namespace std;

class Solution {
   private:
    // 计算下一个位置--交换元素
    void handleCircle(int i, int n, vector<vector<int>>& matrix) {
        int ncircle = n - 1;
        // 定义边界
        const int t = i, r = i + n - 1, b = i + n - 1, l = i;

        // 处理一圈旋转
        for (size_t k = 0; k < ncircle; ++k) {
            int j = l + k;
            int tmp = matrix[i][j];
            // top->right
            i = t + k;
            j = r;
            swap(tmp, matrix[i][j]);
            // right->bottom
            i = b;
            j = r - k;
            swap(tmp, matrix[i][j]);
            // bottom->left
            j = l;
            i = b - k;
            swap(tmp, matrix[i][j]);
            // left->top
            i = t;
            j = l + k;
            swap(tmp, matrix[i][j]);
        }
    }

   public:
    // 以中心旋转,一圈一圈旋转，共最长边/2圈
    // 同一圈需要旋转 边长-1圈，直角旋转需要移动边长-1个step
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size(), ncircle = n / 2;

        int width = n;
        for (size_t i = 0; i < ncircle; i++, width -= 2)
            handleCircle(i, width, matrix);
    }
};

int main(int argc, char const* argv[]) {
    vector<vector<int>> m{{1, 2, 3, 4, 5},
                          {6, 7, 8, 9, 10},
                          {11, 12, 13, 14, 15},
                          {16, 17, 18, 19, 20},
                          {21, 22, 23, 24, 25}};
    Solution().rotate(m);
    for (auto& v : m) {
        for (int a : v) cout << a << " ";
        cout << endl;
    }
    return 0;
}
