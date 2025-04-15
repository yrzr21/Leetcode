#include "../tools.h"

class Solution {
   public:
    int snakesAndLadders(vector<vector<int>>& board) {
        n = board.size();
        int target = n * n;

        // 编号表示
        distance = vector<int>(target + 1, INT32_MAX);
        distance[1] = 0;

        queue<int> q;
        q.push(1);
        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            for (int next = curr + 1; next <= min(curr + 6, target); next++) {
                int r = no2row(next), c = no2col(next);
                if (board[r][c] == -1) {
                    if (!visited(next)) q.push(next);
                    distance[next] = min(distance[curr] + 1, distance[next]);
                } else {
                    if (!visited(board[r][c])) q.push(board[r][c]);
                    distance[board[r][c]] =
                        min(distance[curr] + 1, distance[board[r][c]]);
                }
            }
        }

        return distance[target] == INT32_MAX ? -1 : distance[target];
    }

   private:
    int n;
    vector<int> distance;

    bool visited(int no) { return distance[no] != INT32_MAX; }

    // 对应board中index
    int no2row(int no) { return n - 1 - (no - 1) / n; }
    int no2col(int no) {
        if ((no - 1) / n % 2 == 0)
            return (no - 1) % n;
        else
            return n - 1 - (no - 1) % n;
    }
};

int main(int argc, char const* argv[]) {
    vector<vector<int>> v{{-1, -1, -1}, {-1, 9, 8}, {-1, 8, 9}};
    // vector<vector<int>> v{{-1, -1, -1, -1, -1, -1}, {-1, -1, -1, -1, -1, -1},
    //                       {-1, -1, -1, -1, -1, -1}, {-1, 35, -1, -1, 13, -1},
    //                       {-1, -1, -1, -1, -1, -1}, {-1, 15, -1, -1, -1,
    //                       -1}};
    print_vec_vec(v);
    Solution().snakesAndLadders(v);
    return 0;
}
