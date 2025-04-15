#include "../tools.h"

class Solution {
   private:
    void calculate(stack<int>& nums, char op) {
        int b = nums.top();
        nums.pop();
        int a = nums.top();
        nums.pop();
        if (op == '+') {
            cout << "a+b=" << a + b << endl;
            nums.push(a + b);
        } else if (op == '-') {
            cout << "a-b=" << a - b << endl;
            nums.push(a - b);
        } else if (op == '*') {
            cout << "a*b=" << a * b << endl;
            nums.push(a * b);
        } else {
            cout << "a/b=" << a / b << endl;
            nums.push(a / b);
        }
    }

   public:
    int evalRPN(vector<string>& tokens) {
        stack<int> nums;
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] == "-" || tokens[i] == "+" || tokens[i] == "*" ||
                tokens[i] == "/") {
                calculate(nums, tokens[i][0]);
            } else {
                nums.push(stoi(tokens[i]));
            }
        }

        // cout << "ans=" << nums.top() << endl;
        return nums.top();
    }
};

int main(int argc, char const* argv[]) {
    vector<string> v{"10", "6", "9",  "3", "+", "-11", "*",
                     "/",  "*", "17", "+", "5", "+"};
    Solution().evalRPN(v);
    return 0;
}
