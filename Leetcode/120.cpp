#include "../tools.h"

class Solution {
   public:
    int minimumTotal(vector<vector<int>>& triangle) {
        // dp[i][j] 表示从位置[i][j]抵达底部所需的最小路径和
        // dp[i][j] = min(dp[i+1][j], dp[i+1][j+1])+triangle[i][j]
        int n = triangle.size();
        dp = vector<vector<int>>(n, vector<int>(n, INT32_MAX));

        return minimumTotalI(triangle, 0, 0);
    }

   private:
    vector<vector<int>> dp;

    int minimumTotalI(vector<vector<int>>& triangle, int i, int j) {
        // j不会超出界限，因为下层总比上层多1
        if (i == triangle.size() - 1) return triangle[i][j];
        if (dp[i][j] != INT32_MAX) return dp[i][j];

        dp[i][j] = triangle[i][j] + min(minimumTotalI(triangle, i + 1, j),
                                        minimumTotalI(triangle, i + 1, j + 1));
        return dp[i][j];
    }
};

int main(int argc, char const* argv[]) { return 0; }
