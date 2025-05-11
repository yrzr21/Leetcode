#include "../tools.h"

class Solution {
   public:
    int minDistance(string word1, string word2) {
        // w1[i]!=w2[j], 插入 w2[j] or 替换为w2[j] or 删除 w1[i]
        // w1[i]==w2[j], 下一个

        // dp[i][j]表示使得 w1[i:]==w2[j:] 的最少操作数
        // dp[i][j] = (w1[i]==w2[j]?dp[i+1][j+1]:1+min(dp[i][j+1], dp[i+1][j+1],
        // dp[i+1][j]))

        m = word1.length(), n = word2.length();
        if (n == 0) return m;
        if (m == 0) return n;

        dp = vector<vector<int>>(m + 1, vector<int>(n + 1, 501));
        dp[m][n] = 0;

        return minDistanceIJ(word1, word2, 0, 0);
    }

   private:
    int m, n;

    vector<vector<int>> dp;

    int minDistanceIJ(const string &word1, const string &word2, int i, int j) {
        if (dp[i][j] != 501) return dp[i][j];

        if (i == m) {
            return dp[i][j] = n - j;
        } else if (j == n) {
            return dp[i][j] = m - i;
        }

        if (word1[i] == word2[j]) {
            dp[i][j] = minDistanceIJ(word1, word2, i + 1, j + 1);
        } else {
            dp[i][j] = 1 + min(min(minDistanceIJ(word1, word2, i + 1, j + 1),
                                   minDistanceIJ(word1, word2, i, j + 1)),
                               minDistanceIJ(word1, word2, i + 1, j));
        }
        return dp[i][j];
    }
};

int main(int argc, char const *argv[]) { return 0; }
