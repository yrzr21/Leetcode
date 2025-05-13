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

// 复习1
class Solution2 {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // 对于每个字符串，若排序后存在于map中，则压入答案对应的index中
        // 若map中不存在，则为新异位词，insert
        // map：sorted str,index

        unordered_map<string, int> map;  // sorted str,index
        vector<vector<string>> ans;
        for (size_t i = 0; i < strs.size(); i++) {
            string str = strs[i];
            sort(str.begin(), str.end());

            auto iter = map.find(str);
            if (iter != map.end()) {
                int index = (*iter).second;
                ans[index].push_back(move(strs[i]));
            } else {
                int index = ans.size();
                map.emplace(move(str), index);
                ans.push_back({move(strs[i])});
            }
        }

        return ans;
    }
};
int main(int argc, char const* argv[]) { return 0; }
