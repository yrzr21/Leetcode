#include "../tools.h"

class Solution {
   private:
    bool match(char& l, char& r) {
        if (l == '[')
            return r == ']';
        else if (l == '{')
            return r == '}';
        else
            return r == ')';
    }

   public:
    // 栈存储未匹配字符，遍历完毕 s 时，若栈空则valid
    // 入栈时机：栈空，且字符非右——为左则 false
    bool isValid(string s) {
        stack<char> stk;
        for (char& c : s) {
            if (stk.empty()) {
                if (c == ')' || c == '}' || c == ']')
                    return false;
                else
                    stk.push(c);
            } else {
                if (match(stk.top(), c))
                    stk.pop();
                else
                    stk.push(c);
            }
        }

        return stk.empty();
    }
};

int main(int argc, char const* argv[]) {
    Solution().isValid("()");
    return 0;
}
