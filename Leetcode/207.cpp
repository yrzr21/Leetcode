#include "../tools.h"

class Solution {
   public:
    // 等价于判断有向图有没有环
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        g.resize(numCourses);
        status = vector<int>(numCourses, -1);

        // 构建图
        for (size_t i = 0; i < prerequisites.size(); i++) {
            int from = prerequisites[i][1], to = prerequisites[i][0];
            g[from].push_back(to);
        }

        // 判断先修要求是否成环
        for (size_t i = 0; i < numCourses; i++) {
            if (dfs(i)) return false;  // 不能完成
        }
        return true;
    }

   private:
    // -1 未访问，0正在访问，1已离开
    vector<int> status;

    // g[i] 表示修读课程 i 后才可接着修读的课程
    vector<vector<int>> g;

    // 返回是否成环
    bool dfs(int course_no) {
        if (status[course_no] == 0) return true;
        if (status[course_no] < 0) return true;  // 无需再次访问
        status[course_no] = 0;

        for (size_t j = 0; j < g[course_no].size(); j++) {
            int to = g[course_no][j];
            if (dfs(to)) return true;
        }

        status[course_no] = 1;
        return false;
    }
};

// Kahn 算法
class Solution2 {
   public:
    // 等价于判断有向图有没有环
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // 构建图
        // g[i] 表示修读课程i后可修读的课程，从g[i][1]开始算，g[i][0]表示入度
        vector<vector<int>> g(numCourses, vector<int>(1, 0));
        for (size_t i = 0; i < prerequisites.size(); i++) {
            int from = prerequisites[i][1], to = prerequisites[i][0];
            g[from].push_back(to);
            g[to][0]++;
        }

        queue<int> q;  // 遍历队列
        for (size_t i = 0; i < numCourses; i++) {
            if (g[i][0] == 0) q.push(i);
        }
        int cnt = q.size();

        // 无需，因为一个节点只有一次入度为0的机会
        // vector<bool> visited(numCourses, false);
        while (!q.empty()) {
            int course_no = q.front();
            q.pop();

            for (size_t i = 1; i < g[course_no].size(); i++) {
                int to = g[course_no][i];
                g[to][0]--;
                if (g[to][0] == 0) {
                    cnt++;
                    q.push(to);
                }
            }
        }

        return cnt == numCourses;
    }
};

int main(int argc, char const* argv[]) {
    vector<vector<int>> v{{1, 0}};
    Solution2().canFinish(2, v);

    return 0;
}
