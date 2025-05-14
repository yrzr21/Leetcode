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

// 复习 1
class Solution1 {
   public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() <= 1) return s.length();
        // 快速查找是否在当前子串中：set
        // 维护左右边界：l、r
        // 若不重复，则r++；若出现重复，l++并从set去除，直到不重复
        // 期间记录长度
        unordered_set<char> set;

        int l = 0;
        int maxlen = -1;
        // [l,r)
        for (int r = 0; r < s.length(); r++) {
            if (!set.contains(s[r])) {
                set.insert(s[r]);
                continue;
            }
            maxlen = max(maxlen, r - l); // 放到这里是为了节省不必要的计算
            // erase
            while (s[l] != s[r]) {
                set.erase(s[l++]);
            }
            l++;
        }

        maxlen = max(maxlen, (int)s.length() - l); // 防止结束前没来得及计算
        return maxlen;
    }
};

int main(int argc, char const *argv[]) {
    Solution().lengthOfLongestSubstring("pwwkew");
    return 0;
}
