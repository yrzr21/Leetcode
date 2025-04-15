#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>
#include <memory>
using namespace std;

class Solution {
   public:
    // 抵达边界就变向，更新边界
    // 一次处理一圈
    // 抵达边界：遍历指针==上下左右边界
    // 边界更新：++--
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), total = m * n;
        int left = 0, right = n - 1, top = 0, bottom = m - 1;

        vector<int> ret;
        int cnt = 0;
        int i = 0, j = 0;
        while (left <= right && top <= bottom) {
            for (int i = left; i <= right; i++) ret.push_back(matrix[top][i]);
            top++;

            for (int i = top; i <= bottom; i++) ret.push_back(matrix[i][right]);
            right--;

            if (left > right || top > bottom) break;

            for (int i = right; i >= left; i--)
                ret.push_back(matrix[bottom][i]);
            bottom--;

            for (int i = bottom; i >= top; i--) ret.push_back(matrix[i][left]);
            left++;
        }
        return ret;
    }
};

int main(int argc, char const* argv[]) {
    vector<vector<int>> v{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<int> res = Solution().spiralOrder(v);
    for (int num : res) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
