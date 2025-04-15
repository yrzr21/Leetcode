#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    // 滑动窗口，[l,r]包含sum中元素。sum>target则sum-=nums[l++]若cnt<minCnt则minCnt=cnt
    int minSubArrayLen(int target, vector<int>& nums) {
        int size = nums.size();
        int minCnt = INT32_MAX, sum = 0, cnt = 0;
        int l = 0;
        for (int r = 0; r < size; r++) {
            sum += nums[r];
            cnt++;

            while (sum >= target) {
                sum -= nums[l++];
                if (cnt < minCnt) minCnt = cnt;
                cnt--;
            }
        }
        cout << "minCnt=" << minCnt << endl;
        return minCnt == INT32_MAX ? 0 : minCnt;
    }
};

int main(int argc, char const* argv[]) {
    vector<int> v{2, 3, 1, 2, 4, 3};
    Solution().minSubArrayLen(7, v);
    return 0;
}
