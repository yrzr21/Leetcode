#include "../tools.h"

class Solution {
   public:
    bool wordBreak(string s, vector<string>& wordDict) {
        n = s.size();
        dp = vector<int>(s.length(), -1);

        return wordBreakI(s, 0, wordDict);
    }

   private:
    int n;
    vector<int> dp;  // -1未计算，0不匹配，1匹配
    // 查看dict中的每个单词，比较能否与当前s索引处子字符串匹配
    // 若能，选择，然后继续查看下一个索引处的单词
    // dp[i]表示从i开始的s子字符串能否完全匹配, dp[i]= dp[i+字典中匹配的len]
    // 重复遍历字典或许比较耗时，考虑优化...？
    int wordBreakI(string s, int i, vector<string>& wordDict) {
        if (i == n) return 1;
        if (dp[i] != -1) return dp[i];

        for (size_t j = 0; j < wordDict.size(); j++) {
            string& str = wordDict[j];
            int len = str.length();
            if (len + i > n) continue;

            if (s.substr(i, len) == str)
                dp[i] = wordBreakI(s, len + i, wordDict);

            if (dp[i] == 1) return dp[i];
        }

        return dp[i] = 0;
    }
};

int main(int argc, char const* argv[]) { return 0; }
