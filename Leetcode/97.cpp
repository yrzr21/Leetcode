#include "../tools.h"

class Solution {
   public:
    bool isInterleave(string s1, string s2, string s3) {
        // dp[i][j] 表示 s3[i+j:] 是否由 s1[i:] 和 s2[j:] 组成
        // dp[i][j] = (i!=s1.length && s3[i+j]==s1[i] && dp[i+1][j]) ||
        // (j!=s2.length && s3[i+j]==s2[j] && dp[i][j+1])
        m = s1.length(), n = s2.length();
        if (m + n != s3.length()) return false;
        dp = vector<vector<int>>(m + 1, vector<int>(n + 1, -1));

        return isInterleaveIJ(s1, s2, s3, 0, 0);
    }

   private:
    vector<vector<int>> dp;
    int m, n;
    bool isInterleaveIJ(string &s1, string &s2, string &s3, int i, int j) {
        if (i == m && j == n) {
            return true;
        } else if (i == m) {
            return dp[i][j] = (s3.substr(i + j) == s2.substr(j));
        } else if (j == n) {
            return dp[i][j] = (s3.substr(i + j) == s1.substr(i));
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        bool res = false;
        if (s3[i + j] == s1[i]) {
            res = isInterleaveIJ(s1, s2, s3, i + 1, j);
        }
        if (!res && s3[i + j] == s2[j]) {
            res = isInterleaveIJ(s1, s2, s3, i, j + 1);
        }

        return dp[i][j] = res;
    }
};

int main(int argc, char const *argv[]) { return 0; }
