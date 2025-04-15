#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   private:
    void insert_word(unordered_map<string, int>& target, string& word) {
        if (target.contains(word))
            target[word]++;
        else
            target[move(word)] = 1;
    }

   public:
    // 快速查找words[i]:哈希表
    // 先根据words构建哈希表，然后遍历整个s：
    //      如果当前单词在words中（还需要统计数量），那么插入;若数量超了，那么需要pop;若单词不在，则跳过期间所有单词
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        int wordLen = words[0].size(), size = s.size(), nword = words.size();

        unordered_map<string, int> map;
        for (string& word : words) insert_word(map, word);

        // 每个偏差
        for (int o_start = 0; o_start <= wordLen - 1; o_start++) {
            int start = o_start, i = start, cnt = 0;

            unordered_map<string, int> tmp;
            while (i <= size - wordLen) {
                string word = s.substr(i, wordLen);

                while (tmp.contains(word) && tmp[word] == map[word]) {
                    // 满了，缩短窗口左区间
                    string start_word = s.substr(start, wordLen);
                    if (--tmp[start_word] == 0) tmp.erase(start_word);
                    start += wordLen;
                    cnt--;
                }

                if (map.contains(word)) {
                    // 有这个词，插入。保证不会超过word总数
                    insert_word(tmp, word);
                    cnt++;
                } else {
                    // 没有这个词，跳过期间全部词
                    tmp.clear();
                    cnt = 0;
                    start = i + wordLen;
                }

                if (cnt == nword) {  // 更新答案
                    ans.push_back(start);
                    string start_word = s.substr(start, wordLen);
                    if (--tmp[start_word] == 0) tmp.erase(start_word);
                    cnt--;
                    start += wordLen;
                }
                i += wordLen;
            }
        }

        return move(ans);
    }
};

int main(int argc, char const* argv[]) {
    string s = "barfoofoobarthefoobarman";
    vector<string> v{"bar", "foo", "the"};
    Solution().findSubstring(s, v);
    return 0;
}
