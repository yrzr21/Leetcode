#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
   public:
    // 问题在于如何快速判断当前字符是否在子串中，或许可以用一个map或者一个自定义的函数进行映射。用map吧
    // 滑动窗口进行遍历，[l,r],记录最长长度,while s[r]==s[l]
    // 时移除l，或者set.count(s[r])==1
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> set;
        int size = s.size();
        int l = 0, r = 0;
        int maxlen = 0, cnt = 0;
        while (r < size) {
            while (set.count(s[r]) == 1) {
                set.erase(s[l]);
                l++;
                cnt--;
            }
            set.insert(s[r++]);
            cnt++;

            if (cnt > maxlen) maxlen = cnt;
        }

        return maxlen;
    }
};

int main(int argc, char const *argv[]) {
    Solution().lengthOfLongestSubstring("pwwkew");
    return 0;
}
