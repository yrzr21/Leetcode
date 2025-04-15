#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    // start 和 len 记录当前窗口信息, minlen记录最短的
    // cnt记录已遍历的字符个数，map记录待访问字符
    // 窗口右端点不断滑动，如果visited包含且待访问计数不等于0，则cnt++，否则不做任何操作
    // 若cnt==tsize，左端点滑动到下一个有效字符，原字符计数++，更新minlen
    string minWindow(string s, string t) {
        int ssize = s.size(), tsize = t.size();
        if (tsize > ssize) return "";

        // ssize>tsize
        unordered_map<char, int> target;
        for (char c : t) {
            if (target.contains(c))
                target[c]++;
            else
                target[c] = 1;
        }
        unordered_map<char, int> visited;
        for (char c : t) visited[c] = 0;

        int l = 0, r = 0;  // 窗口
        int cnt = 0;
        int minlen = INT32_MAX, min_start = INT32_MAX;
        while (r < ssize) {
            char c = s[r];
            if (visited.contains(c)) {
                if (visited[c] < target[c]) cnt++;
                visited[c]++;
            }

            if (cnt == tsize) {
                for (bool flag = true; flag;) {
                    flag = false;
                    while (!visited.contains(s[l])) {
                        // 不等于的
                        l++;
                        flag = true;
                    }
                    while (visited.contains(s[l]) &&
                           visited[s[l]] > target[s[l]]) {
                        // 大于的
                        visited[s[l]]--;
                        l++;
                        flag = true;
                    }
                }
                // 此刻左侧在t中，且计数已缩短到最短
                if (r - l + 1 < minlen) {
                    minlen = r - l + 1;
                    min_start = l;
                }
                visited[s[l]]--;
                l++;
                cnt--;
            }

            r++;
        }

        return min_start == INT32_MAX ? "" : s.substr(min_start, minlen);
    }
};

int main(int argc, char const *argv[]) {
    cout << Solution().minWindow("ADOBECODEBANC", "ABC");

    return 0;
}
