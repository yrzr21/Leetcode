#include "../tools.h"

class Solution {
   public:
    int searchInsert(vector<int>& nums, int target) {
        // 左闭右开
        int l = 0;
        int r = nums.size();

        while (l < r) {
            int mid = (l + r) / 2;

            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }

        return l;
    }
};

int main(int argc, char const* argv[]) { return 0; }
