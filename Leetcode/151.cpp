#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
   public:
    // 先遍历一遍字符串，记录每个单词的Index和长度
    // 或者，边遍历边构建
    // 然后用substr重新构建单词，空格只需要留一个就行。前导后驱无空格
    string reverseWords(string s) {
        string ans;
        int size = s.size();
        int end;
        int i = size - 1;

        while (i >= 0) {
            while (i >= 0 && s[i] == ' ') i--;  // 去除后驱空格
            end = i;                            // s[end]!=' '
            if (end < 0) break;
            while (i >= 0 && s[i] != ' ') i--;
            ans += s.substr(i + 1, end - i);
            ans.push_back(' ');
        }
        if (ans.size() != 0) ans.erase(ans.size() - 1);
        return ans;
    }
};

int main(int argc, char const *argv[]) {
    string s = "  hello world  ";
    Solution().reverseWords(s);
    return 0;
}
