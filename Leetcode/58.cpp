#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
   public:
    int lengthOfLastWord(string s) {
        // 从末尾开始遍历，直到碰到空白或者抵达开头
        int i = s.size() - 1;
        while (s[i] == ' ') i--;  // 跳过初始空格
        int end = i;
        while (i >= 0 && s[i] != ' ') i--;  // 跳过字符
        // s[i]=' '或i<0

        if (i < 0)
            return end + 1;
        else
            return end - i;
    }
};
int main(int argc, char const* argv[]) {
    return 0;
}
