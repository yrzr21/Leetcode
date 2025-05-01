#include "../tools.h"

class Solution {
   public:
    Solution() { srand(time(0)); }
    int findKthLargest(vector<int>& nums, int k) {
        return quick_select(nums, nums.size() - k, 0, nums.size() - 1);
    }

   private:
    // 查找升序数组 index k 的数字
    int quick_select(vector<int>& nums, int k, int l, int r) {
        if (l == r) return nums[l];  // 答案只能是他了

        int idx = l + rand() % (r - l + 1);
        int pivot = nums[idx];

        int lt = l - 1, gt = r + 1;
        for (int i = l; i < gt; i++) {
            if (nums[i] < pivot) {
                swap(nums[i], nums[++lt]);
            } else if (nums[i] > pivot) {
                swap(nums[i--], nums[--gt]);
            }
        }

        // 注意，k==lt||k==gt 也得递归
        if (k <= lt) return quick_select(nums, k, l, lt);
        if (k >= gt) return quick_select(nums, k, gt, r);
        return pivot;
    }
};

int main(int argc, char const* argv[]) { return 0; }
