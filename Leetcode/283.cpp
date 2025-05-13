#include "../tools.h"

class Solution {
   public:
    void moveZeroes(vector<int>& nums) {
        // 双指针：i代表最后一个非0元素index，j为遍历指针
        // nums[j]非0，则把它交换到nums[++i]
        // 否则，不动
        int i = -1;
        for (size_t j = 0; j < nums.size(); j++) {
            if (nums[j] == 0) continue;
            swap(nums[++i], nums[j]);
        }
    }
};

int main(int argc, char const* argv[]) { return 0; }
