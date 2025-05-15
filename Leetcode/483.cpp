#include "../tools.h"

class Solution {
   public:
    vector<int> findAnagrams(string s, string p) {
        // 维护一个区间 [l,r)，若已包含所有p中字符，则记录左端点
        // 若某字符超出特定字符数量限制，则pop到该字符
        // 一个标准 mutiset 用于记录p，另一个用于记录当前的
        if (s.empty() || p.empty() || s.size() < p.size()) return {};

        unordered_map<char, int> map;
        for (size_t i = 0; i < p.length(); i++) {
            insertOne(map, p[i]);
        }

        vector<int> ans;

        int l = 0;  // [l,r)
        unordered_map<char, int> cur;
        for (size_t r = 0; r < s.length(); r++) {
            auto map_iter = map.find(s[r]);
            if (map_iter == map.end()) {
                cur.clear();
                l = r + 1;
                continue;
            }
            int cnt = map_iter->second;

            auto iter = cur.find(s[r]);
            if (iter == map.end()) {
                cur.emplace(s[r], 1);
            } else if (iter->second < cnt) {
                iter->second++;
            } else {
                // cur[s[r]] == cnt，pop
                while (s[l] != s[r]) {
                    deleteOne(cur, s[l++]);
                }
                l++;
            }

            // r in range
            if (r - l + 1 == p.size()) {
                ans.push_back(l);
                deleteOne(cur, s[l++]);
            }
        }

        return ans;
    }

   private:
    void insertOne(unordered_map<char, int>& cur, const char& key) {
        auto iter = cur.find(key);
        if (iter == cur.end()) {
            cur.emplace(key, 1);
        } else {
            iter->second++;
        }
    }

    void deleteOne(unordered_map<char, int>& cur, const char& key) {
        auto iter = cur.find(key);
        if (iter->second == 1) {
            cur.erase(iter);
        } else {
            iter->second--;
        }
    }
};

int main(int argc, char const* argv[]) {
    Solution().findAnagrams("cbaebabacd", "abc");
    return 0;
}
