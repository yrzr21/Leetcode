#include "../tools.h"

class Solution {
   public:
    // 尝试将每个位置上的字符修改为 a~z，查看是否在wordList中，bfs
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        unordered_map<string, bool> visited;
        for (size_t i = 0; i < wordList.size(); i++) {
            visited.insert({move(wordList[i]), false});
        }
        if (!visited.contains(endWord)) return 0;

        vector<char> keys;
        for (char c = 'a'; c <= 'z'; c++) keys.push_back(c);

        // bfs
        queue<string> q;
        q.push(move(beginWord));
        int step = 1;  // 当前编号
        while (!q.empty()) {
            int size = q.size();
            // try word
            for (size_t i = 0; i < size; i++) {
                string word = move(q.front());
                q.pop();
                if (word == endWord) return step;

                // try every pos
                for (size_t j = 0; j < word.size(); j++) {
                    // try 'a'-'z'
                    char origin = word[j];
                    for (char key : keys) {
                        if (origin == key) continue;
                        word[j] = key;
                        if (visited.contains(word) && !visited[word]) {
                            visited[word] = true;
                            q.push(word);
                        }
                    }
                    word[j] = origin;
                }
            }
            ++step;
        }

        return 0;
    }
};

int main(int argc, char const* argv[]) {
    vector<string> v{"hot", "dot", "dog", "lot", "log", "cog"};
    Solution().ladderLength("hit", "cog", v);
    return 0;
}
