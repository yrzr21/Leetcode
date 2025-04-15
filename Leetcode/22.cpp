#include "../tools.h"

class Solution {
   public:
    vector<string> generateParenthesis(int n) {
        generateParenthesis(n, 0);
        return move(ans);
    }

   private:
    string cur;
    vector<string> ans;

    // left: 左边尚未匹配的括号总数
    // n:尚未匹配的括号对数
    void generateParenthesis(int n, int left) {
        if (n == 0) {
            ans.push_back(cur);
            return;
        }

        // 剪枝：=n就不能放左括号了
        if (left < n) {
            cur.push_back('(');
            generateParenthesis(n, left + 1);
            cur.pop_back();
        }

        if (left != 0) {
            cur.push_back(')');
            generateParenthesis(n - 1, left - 1);
            cur.pop_back();
        }
    }
};

int main(int argc, char const *argv[]) {
    Solution().generateParenthesis(3);
    return 0;
}
