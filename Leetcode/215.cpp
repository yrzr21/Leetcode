#include "../tools.h"

class Solution {
   public:
    int findKthLargest(vector<int>& nums, int k) {
        // 第k大的元素位于nums[k-1]
        // 遍历数组，将小于nums[k-1]的交换到左边，大于的交换到右边，等于的不动
        int l = 0, r = nums.size() - 1;
        for (size_t i = 0; i < nums.size(); i++) {
            
            if (nums[i] < nums[k - 1]) {
                swap(nums[i], nums[l++]);
            } else if (nums[i] > nums[k - 1]) {
                swap(nums[i], nums[r--]);
            }
        }

        return nums[k - 1];
    }
};

int main(int argc, char const* argv[]) { return 0; }
