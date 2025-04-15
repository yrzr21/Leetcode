#include "../tools.h"

class Solution {
   public:
    // 不可捕获：附近有边界
    // 先标记边界上的，然后遍历board进行捕获
    void solve(vector<vector<char>>& board) {
        m = board.size(), n = board[0].size();

        // 标记边界上的
        for (size_t i = 0; i < m; i++) {
            if (board[i][0] == 'O') mark(board, i, 0);
        }
        for (size_t i = 0; i < m; i++) {
            if (board[i][n - 1] == 'O') mark(board, i, n - 1);
        }
        for (size_t i = 1; i < n; i++) {
            if (board[0][i] == 'O') mark(board, 0, i);
        }
        for (size_t i = 1; i < n; i++) {
            if (board[m - 1][i] == 'O') mark(board, m - 1, i);
        }

        // 捕获
        for (size_t i = 1; i < m; i++) {
            for (size_t j = 1; j < n; j++) {
                if (board[i][j] == 'O') capture(board, i, j);
            }
        }

        // 还原
        for (size_t i = 0; i < m; i++) {
            if (board[i][0] == 'N') unmark(board, i, 0);
        }
        for (size_t i = 0; i < m; i++) {
            if (board[i][n - 1] == 'N') unmark(board, i, n - 1);
        }
        for (size_t i = 1; i < n; i++) {
            if (board[0][i] == 'N') unmark(board, 0, i);
        }
        for (size_t i = 1; i < n; i++) {
            if (board[m - 1][i] == 'N') unmark(board, m - 1, i);
        }
    }

   private:
    int m, n;

    // 标记为X
    void capture(vector<vector<char>>& board, int i, int j) {
        // if (i < 0 || i == m || j < 0 || j == n) // 这个情况不会出现
        if (board[i][j] != 'O') return;  // N或X
        cout << "capture " << i << " " << j << endl;

        board[i][j] = 'X';

        capture(board, i + 1, j);
        capture(board, i - 1, j);
        capture(board, i, j + 1);
        capture(board, i, j - 1);
    }

    // 标记边界上的
    void mark(vector<vector<char>>& board, int i, int j) {
        if (i < 0 || i == m || j < 0 || j == n) return;
        if (board[i][j] != 'O') return;  // X或N
        cout << "mark " << i << " " << j << endl;

        board[i][j] = 'N';

        mark(board, i + 1, j);
        mark(board, i - 1, j);
        mark(board, i, j + 1);
        mark(board, i, j - 1);
    }

    // 还原为0,主要还原边界上的
    void unmark(vector<vector<char>>& board, int i, int j) {
        if (i < 0 || i == m || j < 0 || j == n) return;
        if (board[i][j] != 'N') return;
        cout << "unmark " << i << " " << j << endl;

        board[i][j] = 'O';

        unmark(board, i + 1, j);
        unmark(board, i - 1, j);
        unmark(board, i, j + 1);
        unmark(board, i, j - 1);
    }
};

class Solution2 {
   public:
    // 不可捕获：附近有边界
    // 先标记边界上的，然后遍历board进行捕获
    void solve(vector<vector<char>>& board) {
        m = board.size(), n = board[0].size();

        // 标记边界上的
        for (size_t i = 0; i < m; i++) {
            if (board[i][0] == 'O') mark(board, i, 0);
            if (board[i][n - 1] == 'O') mark(board, i, n - 1);
        }
        for (size_t i = 1; i < n; i++) {
            if (board[0][i] == 'O') mark(board, 0, i);
            if (board[m - 1][i] == 'O') mark(board, m - 1, i);
        }

        // 优化：边捕获边还原
        for (size_t i = 1; i < m; i++) {
            for (size_t j = 1; j < n; j++) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == 'N')
                    board[i][j] = 'O';
            }
        }
    }

   private:
    int m, n;

    // 标记边界上的
    void mark(vector<vector<char>>& board, int i, int j) {
        if (i < 0 || i == m || j < 0 || j == n) return;
        if (board[i][j] != 'O') return;  // X或N
        cout << "mark " << i << " " << j << endl;

        board[i][j] = 'N';

        mark(board, i + 1, j);
        mark(board, i - 1, j);
        mark(board, i, j + 1);
        mark(board, i, j - 1);
    }
};

int main(int argc, char const* argv[]) {
    vector<vector<char>> input{{'O', 'O'}, {'O', 'O'}};
    cout << "input=" << endl;
    print_vec_vec(input);
    Solution().solve(input);

    cout << "output=" << endl;
    print_vec_vec(input);

    return 0;
}
