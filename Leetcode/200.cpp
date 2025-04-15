#include "../tools.h"

class Solution {
   public:
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size(), n = grid[0].size();

        int cnt = 0;
        for (size_t i = 0; i < m; i++) {
            for (size_t j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    mark(grid, i, j);
                    cnt++;
                }
            }
        }
        return cnt;
    }

   private:
    int m, n;
    void mark(vector<vector<char>>& grid, int i, int j) {
        if (i < 0 || i == m || j < 0 || j == n) return;
        if (grid[i][j] == '0') return;
        grid[i][j] = '0';
        mark(grid, i + 1, j);
        mark(grid, i - 1, j);
        mark(grid, i, j - 1);
        mark(grid, i, j + 1);
    }
};
int main(int argc, char const* argv[]) {
    return 0;
}
