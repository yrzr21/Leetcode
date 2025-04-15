#include <iostream>
#include <vector>
using namespace std;

class Solution {
   private:
    int m, n;

    // 设置i,j行列全0
    void setZeroesCol(vector<vector<int>>& matrix, int i, int j) {
        for (size_t k = 0; k < m; k++) {
            matrix[k][j] = 0;
        }
    }
    void setZeroesRow(vector<vector<int>>& matrix, int i, int j) {
        for (size_t k = 0; k < n; k++) {
            matrix[i][k] = 0;
        }
    }

   public:
    void setZeroes(vector<vector<int>>& matrix) {
        m = matrix.size(), n = matrix[0].size();
        // 先找到一个0，然后标记
        int zero_i = -1, zero_j = -1;
        for (size_t i = 0; i < m; i++) {
            for (size_t j = 0; j < n; j++) {
                if (matrix[i][j] != 0) continue;
                zero_i = i;
                zero_j = j;
                break;
            }
            if (zero_i != -1) break;
        }
        if (zero_i == -1) return;

        // matrix[i][j]==0等价于~
        for (size_t i = 0; i < m; i++) {
            for (size_t j = 0; j < n; j++) {
                if (matrix[i][j] != 0) continue;
                matrix[zero_i][j] = 0;
                matrix[i][zero_j] = 0;
            }
        }

        for (size_t j = 0; j < n; j++) {
            if (j == zero_j) continue;
            if (matrix[zero_i][j] == 0) setZeroesCol(matrix, zero_i, j);
        }
        for (size_t i = 0; i < m; i++) {
            if (i == zero_i) continue;
            if (matrix[i][zero_j] == 0) setZeroesRow(matrix, i, zero_j);
        }
        setZeroesCol(matrix, zero_i, zero_j);
        setZeroesRow(matrix, zero_i, zero_j);
    }
};

int main(int argc, char const* argv[]) {
    vector<vector<int>> v{{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
    Solution().setZeroes(v);
    return 0;
}
