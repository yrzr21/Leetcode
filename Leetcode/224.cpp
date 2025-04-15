#include "../tools.h"

class Solution {
   private:
    int fetch_number(const string& s, int& i) {
        int end = i;
        int ret = 0;
        if (s[i] == '-') ++end;
        while (end < s.size() && s[end] >= '0' && s[end] <= '9') {
            ret = ret * 10 + s[end] - '0';
            end++;
        }
        if (s[i] == '-') ret = -ret;
        i = end;
        return i;
    }

    // 计算一个括号
    int solve(const string& s, int& i) {
        while (i < s.size()) {
            if (s[i] == ' ') {
                ++i;
                continue;
            }

            int a = (s[i] == '(') ? solve(s, ++i) : fetch_number(s, i);
            if (i == s.size()) return a;
            char op = s[i++];
            int b = (s[i] == '(') ? solve(s, ++i) : fetch_number(s, i);
            
        }
    }

   public:
    // 无括号则直接计算表达式
    int calculate(string s) {
        int i = 0;
        return solve(s, i);
    }
};
int main(int argc, char const* argv[]) {
    return 0;
}
