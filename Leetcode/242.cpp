#include <string>
#include <unordered_map>
using namespace std;

class Solution {
   public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        unordered_map<char, int> map;
        for (char c : s) {
            if (!map.contains(c))
                map[c] = 1;
            else
                map[c]++;
        }

        for (size_t i = 0; i < t.size(); i++) {
            char c = t[i];
            if (!map.contains(c) || map[c] == 0) return false;
            --map[c];
        }

        return true;
    }
};

int main(int argc, char const *argv[]) {
    string s = "anagram", t = "nagaram";
    Solution().isAnagram(s, t);
    return 0;
}
