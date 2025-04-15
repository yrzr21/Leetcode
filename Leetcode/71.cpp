#include "../tools.h"

class Solution {
   public:
    string simplifyPath(string path) {
        stack<int> parent;
        string ret;
        int i = 0;
        while (i < path.size()) {
            // 跳过所有 /
            while (i < path.size() && path[i] == '/') i++;
            if (i == path.size()) break;

            // 检查 .
            int start = i;
            while (i != path.size() && path[i] == '.') i++;

            if (int n = i - start;
                (i != path.size() && path[i] != '/') || n == 0 || n > 2) {
                ret.push_back('/');
                parent.push(ret.size() - 1);
                // 找到 /
                while (i < path.size() && path[i] != '/') i++;
                ret += path.substr(start, i - start);
            } else if (n == 2) {
                // 非法情形
                if (parent.empty()) {
                    ret.clear();
                } else {
                    ret.erase(parent.top(), ret.size() - parent.top());
                    parent.pop();
                }
            }  // n==1忽略
            cout << "ret=" << ret << endl;
        }
        if (ret.size() == 0) return "/";

        return ret;
    }
};

int main(int argc, char const* argv[]) {
    Solution().simplifyPath("/a//b////c/d//././/..");
    return 0;
}
