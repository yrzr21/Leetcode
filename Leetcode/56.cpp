#include <algorithm>
#include <vector>
using namespace std;

class Solution {
   public:
    static bool compare(const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    }
    // 朴素算法：枚举每个可能的重叠区间，并标记当前区间是否被使用过
    // 算法2：先根据首元素排序，endl<startr的一定是不重叠区间
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), Solution::compare);

        vector<vector<int>> ans = {move(intervals[0])};
        int index = 0;
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= ans[index][1]) {
                ans[index][1] = max(ans[index][1], intervals[i][1]);
            } else {
                ans.emplace_back(move(intervals[i]));
                index++;
            }
        }

        return ans;
    }
};

int main(int argc, char const* argv[]) {
    vector<vector<int>> v{{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    Solution().merge(v);
    return 0;
}
