#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 双指针
class Solution {
   public:
    bool isSubsequence(string s, string t) {
        int si = 0, ti = 0;
        while (si != s.size() && ti != t.size()) {
            if (s[si] == t[ti]) si++;
            ti++;
        }
        return si == s.size();
    }
};

// dp
class Solution2 {
   private:
    const int ntypeofchar = 26;
    // vector<char> charSet;

   private:
    // 转换字符与j
    char getIndex(char c) { return c - 'a'; }

    // 预处理t,记录每个字符后续出现的位置
    // dp[i][j]在t中, 从index i开始，字符j第一次出现的位置
    // dp[i][j]= i if t[i]==t[j] else dp[i+1][j]
    // -1表示没有该字符
    vector<vector<int>> record(const string& t) {
        int size = t.size();

        vector<vector<int>> dp =
            vector<vector<int>>(size, vector<int>(ntypeofchar, -1));

        for (int i = size - 1; i >= 0; i--) {
            // 查看每个字符
            for (char c = 'a'; c <= 'z'; c++) {
                int j = getIndex(c);
                if (t[i] == c)
                    dp[i][j] = i;
                else if (i != size - 1)
                    dp[i][j] = dp[i + 1][j];
            }
        }
        return dp;
    }

   public:
    // 1.预处理t,记录每个字符后续出现的位置
    // 2.遍历s，判断是否为子序列
    bool isSubsequence(string s, string t) {
        vector<vector<int>> dp = record(t);

        int si = 0, ti = 0;
        while (si != s.size() && ti != t.size()) {
            ti = dp[ti][getIndex(s[si])];
            if (ti == -1) return false;
            si++, ti++;
        }

        return si == s.size();
    }
};

int main(int argc, char const* argv[]) {
    Solution2().isSubsequence("abc", "ahbgdc");
    return 0;
}
