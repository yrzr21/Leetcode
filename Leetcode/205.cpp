#include <string>
#include <unordered_map>
using namespace std;

class Solution {
   public:
    // 定义映射规则，每次遇到不同的就加入规则。不符合规则直接返回false
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> rule;
        unordered_map<char, char> reverse;
        for (size_t i = 0; i < s.size(); i++) {
            if (rule.contains(s[i])) {
                if (rule[s[i]] != t[i]) return false;
            } else {
                if (reverse.contains(t[i]))
                    return false;
                else {
                    rule[s[i]] = t[i];
                    reverse[t[i]] = s[i];
                }
            }
        }
        return true;
    }
};

int main(int argc, char const *argv[]) {
    string s = "egg", t = "add";
    Solution().isIsomorphic(s, t);
    return 0;
}
