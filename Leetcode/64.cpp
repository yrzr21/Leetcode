#include "../tools.h"

class Solution {
   public:
    int minPathSum(vector<vector<int>>& grid) {
        // dp[i][j]表示从i,j抵达终点的最短路径和
        // dp[i][j] = grid[i][j] + min(dp[i+1][j],dp[i][j+1])
        int m = grid.size(), n = grid[0].size();

        dp = vector<vector<int>>(m, vector<int>(n, INT32_MAX));
        // 初始化dp
        int cnt = 0;
        for (int i = m - 1; i >= 0; i--) {
            cnt += grid[i][n - 1];
            dp[i][n - 1] = cnt;
        }
        cnt = 0;
        for (int i = n - 1; i >= 0; i--) {
            cnt += grid[m - 1][i];
            dp[m - 1][i] = cnt;
        }

        return minPathSumI(grid, 0, 0);
    }

   private:
    vector<vector<int>> dp;
    int m, n;

    int minPathSumI(vector<vector<int>>& grid, int i, int j) {
        if (dp[i][j] != INT32_MAX) return dp[i][j];

        dp[i][j] = grid[i][j] + min(minPathSumI(grid, i + 1, j),
                                    minPathSumI(grid, i, j + 1));
        return dp[i][j];
    }
};

int main(int argc, char const* argv[]) { return 0; }
