#include <string>
#include <unordered_map>
using namespace std;

class Solution {
   private:
    int wordLen(string& s, int i) {
        int len = 0;
        while (i < s.size() && s[i++] != ' ') len++;
        return len;
    }

   public:
    // 每个新字母则增加映射，旧字母不等则返回false
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> map;
        unordered_map<string, char> reverse;
        int si = 0;
        for (int i = 0; i < pattern.size(); i++, si++) {
            if (si >= s.size()) return false;

            char c = pattern[i];
            int length = wordLen(s, si);
            string str = s.substr(si, length);

            if (map.contains(c)) {
                if (map[c] != str) return false;
                si += length;
            } else if (reverse.contains(str)) {
                return false;
            } else {
                map[c] = move(str);
                reverse[map[c]] = c;
                si += length;
            }
        }
        if (si < s.size()) return false;
        return true;
    }
};

int main(int argc, char const* argv[]) {
    string s = "abba", t = "dog dog dog dog";
    Solution().wordPattern(s, t);
    return 0;
}
