#include <iostream>
#include <vector>
using namespace std;

class Solution {
   private:
    using Board = vector<vector<int>>;

    int m, n;
    int count_alive(Board& b, int i, int j) {
        int ret = 0;
        if (i != 0 && j != 0 && (b[i - 1][j - 1] == 1 || b[i - 1][j - 1] == -1))
            ret++;
        if (i != 0 && (b[i - 1][j] == 1 || b[i - 1][j] == -1)) ret++;
        if (i != 0 && j != n - 1 &&
            (b[i - 1][j + 1] == 1 || b[i - 1][j + 1] == -1))
            ret++;
        if (j != 0 && (b[i][j - 1] == 1 || b[i][j - 1] == -1)) ret++;
        if (j != n - 1 && (b[i][j + 1] == 1 || b[i][j + 1] == -1)) ret++;
        if (j != 0 && i != m - 1 &&
            (b[i + 1][j - 1] == 1 || b[i + 1][j - 1] == -1))
            ret++;
        if (i != m - 1 && (b[i + 1][j] == 1 || b[i + 1][j] == -1)) ret++;
        if (i != m - 1 && j != n - 1 &&
            (b[i + 1][j + 1] == 1 || b[i + 1][j + 1] == -1))
            ret++;
        return ret;
    }

   public:
    void gameOfLife(vector<vector<int>>& board) {
        // 遍历，复生的状态设为2，从生到死设为-1，仅统计为1的
        m = board.size(), n = board[0].size();

        for (size_t i = 0; i < m; i++) {
            for (size_t j = 0; j < n; j++) {
                int around_alive = count_alive(board, i, j);
                if ((around_alive < 2 || around_alive > 3) && board[i][j] == 1)
                    board[i][j] = -1;
                else if (around_alive == 3 && board[i][j] == 0)
                    board[i][j] = 2;
                // 其余维持不变
            }
        }

        for (size_t i = 0; i < m; i++) {
            for (size_t j = 0; j < n; j++) {
                if (board[i][j] == -1)
                    board[i][j] = 0;
                else if (board[i][j] == 2)
                    board[i][j] = 1;
            }
        }
    }
};

int main(int argc, char const* argv[]) {
    vector<vector<int>> v{{0, 1, 0}, {0, 0, 1}, {1, 1, 1}, {0, 0, 0}};
    Solution().gameOfLife(v);
    return 0;
}
