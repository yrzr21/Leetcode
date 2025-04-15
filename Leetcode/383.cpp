#include <string>
#include <unordered_map>
using namespace std;

class Solution {
   public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> map;
        for (char c : ransomNote) {
            if (map.contains(c))
                map[c]++;
            else
                map[c] = 1;
        }

        for (char c : magazine) {
            if (!map.contains(c)) continue;
            map[c]--;
            if (map[c] == 0) map.erase(c);
        }
        return map.size() == 0;
    }
};
int main(int argc, char const* argv[]) {
    return 0;
}
