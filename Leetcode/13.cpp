#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
   public:
    // 假定给定罗马数字合法
    // 从末尾开始遍历
    // 对于s[i]: =current则cnt+=~, <current则cnt-=~, >current则更新current,+=
    int romanToInt(string s) {
        unordered_map<char, int> rule{{'I', 1},   {'V', 5},   {'X', 10},
                                      {'L', 50},  {'C', 100}, {'D', 500},
                                      {'M', 1000}};

        char current = s[s.size() - 1];
        int cnt = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == current)
                cnt += rule[current];
            else if (rule[s[i]] < rule[current])
                cnt -= rule[s[i]];
            else {
                current = s[i];
                cnt += rule[current];
            }
        }
        return cnt;
    }
};

int main(int argc, char const* argv[]) {
    Solution().romanToInt("MCMXCIV");
    return 0;
}
