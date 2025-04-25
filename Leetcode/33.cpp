#include "../tools.h"

class Solution {
   public:
    // 一般来讲有：l<x<r，考虑搜索，除去正常二分外，假设n-1此时的index为z：
    // 若mid<=z，则 l<mid>r，若mid>z，则l>mid<r
    // 1. 对于前者，有 l<target<mid<=z>r，舍弃右边；或
    // l<mid<z?target>r，舍弃左边
    // 2. 对于后者，若 l>target>mid>z<r，舍弃右边；或 l>mid>z?target<r，舍弃左边
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size();
        while (l < r) {
            int mid = (l + r) / 2;
            if (target == nums[mid]) return mid;

            if (nums[l] <= nums[mid]) {
                if (target >= nums[l] && target < nums[mid]) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            } else {
                if (target <= nums[r - 1] && target > nums[mid]) {
                    l = mid + 1;
                } else {
                    r = mid;
                }
            }
        }

        return -1;
    }
};

int main(int argc, char const* argv[]) { return 0; }
