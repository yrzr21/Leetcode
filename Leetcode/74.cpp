#include "../tools.h"

// 先按列二分搜索，再按行二分
class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        if (target < matrix[0][0] || target > matrix[m - 1][n - 1])
            return false;

        int l = 0;
        int r = m;  // 左闭右开
        int row = -1;
        while (l < r) {
            int mid = (l + r) / 2;

            if (matrix[mid][0] == target || matrix[mid][n - 1] == target) {
                return true;
            } else if (target < matrix[mid][0]) {
                r = mid;
            } else if (target < matrix[mid][n - 1]) {
                row = mid;
                break;
            } else {
                l = mid + 1;
            }
        }
        if (row < 0) row = l;

        l = 0;
        r = n;
        while (l < r) {
            int mid = (l + r) / 2;

            if (matrix[row][mid] == target) {
                return true;
            } else if (matrix[row][mid] < target) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }

        return false;
    }
};

int main(int argc, char const* argv[]) { return 0; }
