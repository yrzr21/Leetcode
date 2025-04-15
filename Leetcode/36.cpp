#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    // 定义接口：本行、列、宫数字x所在的位置
    // 遍历整个矩阵，判断非空白处的数字是否在本行、列、宫的其他位置出现过
    // 不可能有重复执行的部分，那会直接返回错误
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<int>> visited =
            vector<vector<int>>(board.size(), vector<int>(board[0].size(), 0));
        vector<vector<int>> row_visited =
            vector<vector<int>>(board.size(), vector<int>(board[0].size(), 0));
        vector<vector<int>> col_visited =
            vector<vector<int>>(board.size(), vector<int>(board[0].size(), 0));
        // 预处理
        for (size_t i = 0; i < board.size(); i++) {
            for (size_t j = 0; j < board[0].size(); j++) {
                if (board[i][j] == '.') continue;
                int num = board[i][j] - '0';
                row_visited[i][num - 1]++;
                col_visited[num - 1][j]++;
                visited[(i / 3) * 3 + j / 3][num - 1]++;
            }
        }

        // 计算
        for (size_t i = 0; i < board.size(); i++) {
            for (size_t j = 0; j < board[0].size(); j++) {
                if (board[i][j] == '.') continue;

                int num = board[i][j] - '0';
                if (row_visited[i][num - 1] > 1 ||
                    col_visited[num - 1][j] > 1 ||
                    visited[(i / 3) * 3 + j / 3][num - 1] > 1)
                    return false;
            }
        }
        return true;
    }
};

int main(int argc, char const* argv[]) {
    vector<vector<char>> v{{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                           {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                           {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                           {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                           {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                           {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                           {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                           {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                           {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    Solution().isValidSudoku(v);
    return 0;
}
