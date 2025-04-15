#include "../tools.h"

// dfs
class Solution {
   public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // 构建图
        graph.resize(numCourses);
        status = vector<int>(numCourses, -1);

        for (size_t i = 0; i < prerequisites.size(); i++) {
            int from = prerequisites[i][1], to = prerequisites[i][0];
            graph[from].push_back(to);
        }

        // 检测环
        for (size_t i = 0; i < numCourses; i++) {
            if (dfs(i)) return {};
        }

        reverse(post.begin(), post.end());
        return post;
    }

   private:
    vector<int> status;  // -1 0 1
    vector<int> post;    // 离开顺序
    vector<vector<int>> graph;

    // 返回是否有环
    bool dfs(int course_no) {
        if (status[course_no] == 0) return true;  // 访问时再次访问
        if (status[course_no] > 0) return false;  // 另一条入边，无需再次访问
        status[course_no] = 0;

        for (int out : graph[course_no]) {
            if (dfs(out)) return true;
        }

        status[course_no] = 1;
        post.push_back(course_no);
        return false;
    }
};

// bfs
class Solution2 {
   public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // 构建图
        vector<vector<int>> graph(numCourses);
        vector<int> in_cnt(numCourses, 0);
        for (size_t i = 0; i < prerequisites.size(); i++) {
            int from = prerequisites[i][1], to = prerequisites[i][0];
            graph[from].push_back(to);
            in_cnt[to]++;
        }

        // 找入度为0的
        queue<int> q;
        vector<int> ans;
        for (size_t i = 0; i < numCourses; i++) {
            if (in_cnt[i] == 0) {
                q.push(i);
                ans.push_back(i);
            }
        }

        // bfs
        int cnt = q.size();
        while (!q.empty()) {
            int from = q.front();
            q.pop();

            // 削减入度
            for (size_t i = 0; i < graph[from].size(); i++) {
                int to = graph[from][i];
                in_cnt[to]--;
                if (in_cnt[to] == 0) {
                    cnt++;
                    q.push(to);
                    ans.push_back(to);
                }
            }
        }

        return cnt == numCourses ? move(ans) : vector<int>{};
    }
};

int main(int argc, char const* argv[]) {
    vector<vector<int>> v{{1, 0}};
    Solution().findOrder(2, v);

    return 0;
}
