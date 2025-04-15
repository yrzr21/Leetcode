#include "../tools.h"

class Solution {
   public:
    // 回溯。记录单词的长度，长度相等时比较？有些浪费，记录下一个字母是谁，在上下左右找，没字母即有，直接返回
    // 需要Bool数组记录是否访问？似乎是...考虑优化，哈希表+栈？emm是可以，但还是先用数组吧
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        visited = vector<vector<bool>>(m, vector<bool>(n, false));
        this->word = move(word);

        for (size_t i = 0; i < m; i++) {
            for (size_t j = 0; j < n; j++) {
                exist(board, 0, i, j);
                if(is_exist)return true;
            }
        }
        return false;
    }

   private:
    vector<vector<bool>> visited;
    int m;
    int n;
    int is_exist = false;

    string word;
    // ij:当前待查看位置，c_i：下一个待匹配的单词位置
    void exist(vector<vector<char>>& board, int c_i, int i, int j) {
        if (is_exist) return;  // 已有答案，不再考虑

        if (c_i == word.size()) {
            is_exist = true;
            return;
        }
        if (i < 0 || i == m || j < 0 || j == n) return;
        if (visited[i][j]) return;
        if (board[i][j] != word[c_i]) return;

        // 考虑访问上下左右
        visited[i][j] = true;
        exist(board, c_i + 1, i + 1, j);
        exist(board, c_i + 1, i - 1, j);
        exist(board, c_i + 1, i, j + 1);
        exist(board, c_i + 1, i, j - 1);
        visited[i][j] = false;
    }
};

int main(int argc, char const* argv[]) { return 0; }
