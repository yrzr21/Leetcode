#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
   public:
    // 单词间至少一个空格
    // nword表示本行单词数，wordlen表示本行单词总长度（不含空格），则本行长度=nword-1+wordlen，末尾无空格，即
    // |word1 word2...wordx wordx+1|的形式

    // 循环中处理，每个循环处理一行
    // 若加上下一个单词后长度<=maxWidth,则继续添加
    // 若> 则立刻开始处理原始行

    // 处理方式：先计算空格，多的空格全放第一个后面，其他单词间隔只有一个空格
    // 若为最后一行需做特殊处理
    // 判定最后一行：到达words末尾
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int size = words.size();
        int i = 0;

        vector<string> ret;
        while (i < size) {
            int start = i, nword = 1, wordslen = words[i].size();
            i++;

            while (i != size &&
                   wordslen + words[i].size() + nword <= maxWidth) {
                wordslen += words[i++].size();
                nword++;
            }
            // words[i]放不下或者i==size

            string line;
            if (i == size) {
                for (size_t j = 0; j < nword - 1; j++) {
                    line.append(move(words[start + j]));
                    line.append(string(1, ' '));
                }
                line.append(move(words[start + nword - 1]));
                line.append(string(maxWidth - line.size(), ' '));
            } else if (nword == 1) {
                line.append(move(words[start]));
                line.append(string(maxWidth - wordslen, ' '));
            } else {
                int nspace = (maxWidth - wordslen) / (nword - 1);
                int extra = (maxWidth - wordslen) % (nword - 1);

                for (size_t j = 0; j < nword - 1; j++) {
                    line.append(move(words[start + j]));
                    line.append(string(nspace, ' '));
                    // 有 extra个单词需要额外1个间隔
                    if (extra-- > 0) line.append(string(1, ' '));
                }
                line.append(move(words[start + nword - 1]));
            }
            ret.push_back(move(line));
        }
        return ret;
    }
};

int main(int argc, char const* argv[]) {
    vector<string> v{"ask", "not", "what", "your", "country", "can",
                     "do",  "for", "you",  "ask",  "what",    "you",
                     "can", "do",  "for",  "your", "country"};
    vector<string> res = Solution().fullJustify(v, 16);
    for (auto s : res) cout << s << "|" << endl;
    return 0;
}
