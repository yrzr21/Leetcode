#include "../tools.h"

class Solution {
   public:
    // mid 为峰值则返回，
    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        int n = nums.size();
        // 答案在边界
        if (nums[0] > nums[1]) return 0;
        if (nums[n - 1] > nums[n - 2]) return n - 1;

        int l = 0;
        int r = n;
        while (l < r) {
            int mid = (l + r) / 2;

            if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) {
                return mid;
            } else if (nums[mid] > nums[mid - 1] && nums[mid] < nums[mid + 1]) {
                l = mid + 1;
            } else {
                // l>x<r，或 l>x>r
                r = mid;
            }
        }

        // 这里应该到不了
        return -1;
    }
};

int main(int argc, char const* argv[]) {
    // vec_int v{6, 5, 4, 3, 2, 3, 2};
    // Solution().findPeakElement(v);

    vec_int v;
    v.reserve(17);
    cout << v.capacity() << endl;
    cout << v.size() << endl;
    cout << v[6] << endl;
    return 0;
}
