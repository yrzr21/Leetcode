#include "../tools.h"

class Solution {
   public:
    static bool compare(const vector<int>& l, const vector<int>& r) {
        return l[0] < r[0];
    }
    // 合并区间，到不重叠，计算长度，返回长度
    // 先排序
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.size() == 1) return 1;

        sort(points.begin(), points.end(), Solution::compare);

        int narrow = 0;
        int l = points[0][0], r = points[0][1];
        for (int i = 1; i < points.size(); i++) {
            if (points[i][0] > r) {
                narrow++;
                l = points[i][0];
                r = points[i][1];
            } else {
                l = points[i][0];
                r = min(points[i][1], r);
            }
        }
        return ++narrow;
    }
};
int main(int argc, char const* argv[]) {
    vector<vector<int>> v{{3, 9}, {7, 12}, {3, 8}, {6, 8}, {9, 10},
                          {2, 9}, {0, 9},  {3, 9}, {0, 6}, {2, 8}};
    cout << Solution().findMinArrowShots(v);
    return 0;
}
