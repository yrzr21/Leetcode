#include "../tools.h"

class Solution {
   public:
    string longestPalindrome(string s) {
        // dp[i][j]表示s[i:j]是否是回文串
        // dp[i][j] = s[i]==s[j] && dp[i-1][j]
        // 若不是，则可查看：dp[i+1][j],dp[i+1][j-1],dp[i][j-1]
        // base case: len ==0||len==1，必回文

        n = s.size();
        dp = vector<vector<int>>(n, vector<int>(n, -1));
        for (size_t i = 0; i < n; i++) {
            dp[i][i] = 1;
        }

        return s.substr(ans_i, len);
    }

   private:
    int n;
    int ans_i = 0, len = -1;
    vector<vector<int>> dp;
    bool longestPalindromeIJ(string s, int i, int j) {
        if (i > j) return 1;
        if (dp[i][j] != -1) return dp[i][j];

        if (s[i] == s[j] && longestPalindromeIJ(s, i + 1, j - 1)) {
            dp[i][j] = 1;
            if (len < j - i + 1) {
                ans_i = i;
                len = j - i + 1;
            }
        } else {
            
        }
    }
};

int main(int argc, char const *argv[]) { return 0; }
