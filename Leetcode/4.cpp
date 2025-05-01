#include "../tools.h"

class Solution {
   public:
    // compare A[l1+k/2-1] and B[l2+k/2-1],舍弃较小者的左半部分，相等则都舍弃
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        if (m + n == 1) return nums1.size() == 1 ? nums1[0] : nums2[0];
        bool is_even = ((m + n) % 2 == 0);

        int k = (m + n + 1) / 2;

        int l1 = 0, l2 = 0;
        while (true) {
            if (l1 == m) {
                return is_even ? (nums2[l2 + k - 1] + nums2[l2 + k]) / 2.0
                               : nums2[l2 + k - 1];
            }
            if (l2 == n) {
                return is_even ? (nums1[l1 + k - 1] + nums1[l1 + k]) / 2.0
                               : nums1[l1 + k - 1];
            }

            if (k == 1) {
                if (nums1[l1] == nums2[l2]) return nums1[l1];
                if (!is_even) return min(nums1[l1], nums2[l2]);
                if (l1 == m - 1 || l2 == n - 1)
                    return (nums1[l1] + nums2[l2]) / 2.0;

                if (nums1[l1] < nums2[l2]) {
                    return (nums1[l1] + min(nums1[l1 + 1], nums2[l2])) / 2.0;
                } else {
                    return (nums2[l2] + min(nums2[l2 + 1], nums1[l1])) / 2.0;
                }
            }

            int i1 = max(0, min(l1 + k / 2 - 1, m - 1));
            int i2 = max(0, min(l2 + k / 2 - 1, m - 1));
            if (nums1[i1] == nums2[i2]) {
                k -= (i1 - l1 + i2 - l2 + 2);
                l1 = i1 + 1;
                l2 = i2 + 1;
            } else if (nums1[i1] < nums2[i2]) {
                k -= (i1 - l1 + 1);
                l1 = i1 + 1;
            } else {
                k -= (i2 - l2 + 1);
                l2 = i2 + 1;
            }
        }

        // 不会抵达这里
        return -1;
    }
};

int main(int argc, char const* argv[]) {
    vec_int v1{1, 3}, v2{2};
    cout << Solution().findMedianSortedArrays(v1, v2);
    return 0;
}
