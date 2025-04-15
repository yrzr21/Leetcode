#include "../tools.h"

class Solution {
   public:
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) return {};

        this->digits = move(digits);
        string cur;
        backtrack(cur, 0);

        return ans;
    }

   private:
    vector<string> map{"abc", "def",  "ghi", "jkl",
                       "mno", "pqrs", "tuv", "wxyz"};
    vector<string> ans;
    string digits;

    string& number_to_alphas(int no) { return map[no - 2]; }

    // i:下一个组合的数字index
    void backtrack(string& cur, int i) {
        if (i == digits.size()) {
            ans.push_back(cur);
            return;
        }

        const string& letters = number_to_alphas(digits[i] - '0');
        for (char letter : letters) {
            cur.push_back(letter);
            backtrack(cur, i + 1);
            cur.pop_back();
        }
    }
};

int main(int argc, char const* argv[]) { return 0; }