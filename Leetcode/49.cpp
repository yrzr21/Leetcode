#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> sorted_strs;
        for (string str : strs) {
            sort(str.begin(), str.end());
            sorted_strs.emplace_back(move(str));
        }
        unordered_map<string, vector<string>> map;
        for (size_t i = 0; i < strs.size(); i++) {
            if (map.contains(sorted_strs[i]))
                map[sorted_strs[i]].emplace_back(move(strs[i]));
            else
                map[sorted_strs[i]] = {move(strs[i])};
        }

        vector<vector<string>> ans;
        for (auto& vs : map) {
            ans.emplace_back(move(vs.second));
        }

        return ans;
    }
};
int main(int argc, char const* argv[]) {
    return 0;
}
