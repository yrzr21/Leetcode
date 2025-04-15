#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
   public:
    string longestCommonPrefix(vector<string>& strs) {
        int size = strs.size();
        if (size == 1) return strs[0];
        string ans = strs[0];

        // 记录目前为止最长公共前缀长度
        // 遍历整个字符串串，若小于当前长度则更新长度
        // 最后更新字符串ans

        int len = ans.size();
        for (string& s : strs) {
            size_t i = 0;  // 相等的长度
            while (i < s.size() && i < ans.size() && s[i] == ans[i]) i++;
            if (i == 0)
                return "";
            else if (i < len)
                len = i;
        }
        return ans.substr(0, len);
    }
};

int main(int argc, char const* argv[]) { return 0; }
