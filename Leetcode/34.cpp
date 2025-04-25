#include "../tools.h"

class Solution {
   public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = findStart(nums, 0, nums.size(), target);
        if (start < 0) return {-1, -1};
        int end = findEnd(nums, start, nums.size(), target);
        return {start, end};
    }

   private:
    // [l,r)
    int findStart(vector<int>& nums, int l, int r, int target) {
        int ans = -1;
        while (l < r) {
            int mid = (l + r) / 2;
            if (target == nums[mid]) {
                ans = mid;
                r = mid;
            } else if (target > nums[mid]) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }

        return ans;
    }
    int findEnd(vector<int>& nums, int l, int r, int target) {
        int ans = -1;
        while (l < r) {
            int mid = (l + r) / 2;
            if (target == nums[mid]) {
                ans = mid;
                l = mid + 1;
            } else if (target > nums[mid]) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }

        return ans;
    }
};

int main(int argc, char const* argv[]) { return 0; }
