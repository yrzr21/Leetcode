#include "../tools.h"

class Solution {
   public:
    int maximalSquare(vector<vector<char>>& matrix) {
        // dp[i][j] 表示以ij为右下顶点正方形的最大边长
        // dp[i][j] = matrix[i][j]==1 ?
        // 1+min(dp[i-1][j-1],dp[i][j-1],dp[i-1][j]): 0;
        m = matrix.size(), n = matrix[0].size();

        dp = vector<vector<int>>(m, vector<int>(n, -1));
        // init dp
        int ans = 0;
        for (size_t i = 0; i < m; i++) {
            dp[i][0] = (matrix[i][0] == '1');
            if (dp[i][0]) ans = 1;
        }
        for (size_t i = 1; i < n; i++) {
            dp[0][i] = (matrix[0][i] == '1');
            if (dp[0][i]) ans = 1;
        }

        for (size_t i = 1; i < m; i++) {
            for (size_t j = 1; j < n; j++) {
                ans = max(ans, maximalSquareIJ(matrix, i, j));
            }
        }

        return ans * ans;
    }

   private:
    int m, n;
    vector<vector<int>> dp;

    int maximalSquareIJ(vector<vector<char>>& matrix, int i, int j) {
        if (dp[i][j] != -1) return dp[i][j];
        if (matrix[i][j] == '0') return dp[i][j] = 0;

        int n1 = maximalSquareIJ(matrix, i - 1, j - 1);
        int n2 = maximalSquareIJ(matrix, i, j - 1);
        int n3 = maximalSquareIJ(matrix, i - 1, j);

        return dp[i][j] = 1 + min(n1, min(n2, n3));
    }
};

int main(int argc, char const* argv[]) { return 0; }
