#include "../tools.h"

class Solution {
   public:
    // 假设最小值位于索引z，那么进行二分，除正常二分外有如下结果：
    // 对于l>r:
    // 1.l < mid >z>r，l=mid+1
    // 2.l > z<=mid >r，r=mid
    // 对于l<r：ans=l
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            if (nums[l] <= nums[r]) return nums[l];
            // l==mid？，仅有两个元素时
            if (l + 1 == r) return min(nums[l], nums[r]);

            int mid = (l + r) / 2;
            // l>r，l!=mid
            if (nums[l] < nums[mid]) {  // mid!=z
                l = mid + 1;
            } else {
                // >
                r = mid;
            }
        }

        // 这里应到到不了
    }
};

int main(int argc, char const* argv[]) { return 0; }
