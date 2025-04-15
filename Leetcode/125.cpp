#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
   private:
    string to_letter_digital(const string &s) {
        string ret;
        for (char c : s)
            if (isalnum(c)) ret.push_back(tolower(c));
        return ret;
    }

   public:
    // 1.转换为纯小写字母数字字符
    // 2.验证回文序列
    bool isPalindrome(string s) {
        string let_dig = to_letter_digital(s);

        int l = 0, r = let_dig.size() - 1;
        while (l < r && let_dig[l] == let_dig[r]) l++, r--;
        // s[l]!=s[r] 或 l>=r
        return l >= r;
    }
};

int main(int argc, char const *argv[]) {
    Solution().isPalindrome("A man, a plan, a canal: Panama");
    return 0;
}
