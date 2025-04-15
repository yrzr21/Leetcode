#include "../tools.h"

class Solution {
   public:
    int totalNQueens(int n) {
        col_choosed.resize(n);
        left_choosed.resize(2 * n - 1);
        right_choosed.resize(2 * n - 1);

        this->n = n;
        backtrack(0);
        return ans;
    }

   private:
    int ans = 0;
    int n;
    vector<bool> col_choosed;
    vector<bool> left_choosed;   // 左上到右下
    vector<bool> right_choosed;  // 右上到左下

    void choose(int r, int c) {
        col_choosed[c] = true;
        left_choosed[r - c + n - 1] = true;
        right_choosed[r + c] = true;
    }
    void cancel(int r, int c) {
        col_choosed[c] = false;
        left_choosed[r - c + n - 1] = false;
        right_choosed[r + c] = false;
    }

    // 给定合法的行，判断列和斜线是否合法
    bool valid(int r, int c) {
        cout << "r=" << r << ",c=" << c << ", left=" << r + c + n - 1
             << ", right=" << r + c << endl;
        return !col_choosed[c] && !left_choosed[r - c + n - 1] &&
               !right_choosed[r + c];
    }

    // 枚举一行的n个位置，检测合法性，合法则加入组合，递归检测下一行
    void backtrack(int row) {
        // 解可行
        if (row == n) {
            ans++;
            return;
        }

        for (size_t col = 0; col < n; col++) {
            if (!valid(row, col)) continue;
            choose(row, col);
            backtrack(row + 1);
            cancel(row, col);
        }
    }
};

int main(int argc, char const *argv[]) {
    Solution().totalNQueens(4);
    return 0;
}
