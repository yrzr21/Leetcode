#include "../tools.h"

class Solution {
   public:
    // 找左右端点落入的区间 index，合并
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {
        if (intervals.size() == 0) return {move(newInterval)};

        int lindex = -1, rindex = -1;
        int l = newInterval[0], r = newInterval[1];
        for (size_t i = 0; i < intervals.size(); i++) {
            if (l <= intervals[i][1]) {
                l = min(l, intervals[i][0]);
                lindex = i;
                break;
            }
        }
        if (lindex == -1) {
            intervals.emplace_back(move(newInterval));
            return intervals;
        }

        for (size_t i = lindex; i < intervals.size(); i++) {
            if (r < intervals[i][0]) {
                if (i == lindex) {
                    intervals.insert(intervals.begin() + lindex, {l, r});
                    return intervals;
                } else {
                    rindex = i - 1;
                    break;
                }
            } else if (r <= intervals[i][1]) {
                r = intervals[i][1];
                rindex = i;
                break;
            }
        }
        if (rindex == -1) rindex = intervals.size() - 1;

        // 跳过 [lindex, rindex]
        intervals.erase(intervals.begin() + lindex,
                        intervals.begin() + rindex + 1);
        intervals.insert(intervals.begin() + lindex, {l, r});
        return intervals;
    }
};

int main(int argc, char const* argv[]) {
    vector<vector<int>> v{{1, 5}};
    vector<int> v1{0, 0};
    print_vec_vec(Solution().insert(v, v1));
    return 0;
}
