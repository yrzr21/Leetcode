#include "../tools.h"

class Solution {
   public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        // dp[i][j]表示从index i j出发抵达终点的路径数
        // 初始化：从终点往左/上走，遇到障碍物后，后续所有dp为0
        // dp[i][j] = dp[i+1][j]+dp[i][j+1],路径不会重复

        m = obstacleGrid.size(), n = obstacleGrid[0].size();

        // 初始化
        dp = vector<vector<int>>(m, vector<int>(n, INT32_MAX));
        bool has_obstacle = false;
        for (int i = m - 1; i >= 0; i--) {
            if (obstacleGrid[i][n - 1] == 1) has_obstacle = true;

            dp[i][n - 1] = (has_obstacle ? 0 : 1);
        }
        has_obstacle = false;
        for (int i = n - 1; i >= 0; i--) {
            if (obstacleGrid[m - 1][i] == 1) has_obstacle = true;

            dp[m - 1][i] = (has_obstacle ? 0 : 1);
        }

        // 计算
        return uniquePathsWithObstaclesI(obstacleGrid, 0, 0);
    }

   private:
    int m, n;
    vector<vector<int>> dp;  // 0表示无法抵达终点,-1未初始化

    int uniquePathsWithObstaclesI(vector<vector<int>>& g, int i, int j) {
        if (dp[i][j] != INT32_MAX) return dp[i][j];
        if (g[i][j] == 1) return 0;

        dp[i][j] = uniquePathsWithObstaclesI(g, i + 1, j) +
                   uniquePathsWithObstaclesI(g, i, j + 1);
        return dp[i][j];
    }
};
int main(int argc, char const* argv[]) { return 0; }
