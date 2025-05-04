#include "../tools.h"

class Solution {
   public:
    using IntPair = pair<int, int>;
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2,
                                       int k) {
        // 0 0--0 1/1 0，即入队ai+1,bi 和 ai,bi+1
        // 重复问题：哈希表 or 入队ai,0 然后递增bi入队
        auto cmp = [&nums1, &nums2](const IntPair& a, const IntPair& b) {
            return nums1[a.first] + nums2[a.second] >
                   nums1[b.first] + nums2[b.second];
        };

        priority_queue<IntPair, vector<IntPair>, decltype(cmp)> pq(cmp);

        int m = nums1.size();
        int n = nums2.size();
        for (size_t i = 0; i < min(m, k); i++) {
            pq.emplace(i, 0);
        }

        vector<vector<int>> ans;
        // do k times. pq will not be empty
        for (size_t i = 0; i < k; i++) {
            auto [idx1, idx2] = pq.top();
            pq.pop();

            ans.push_back({nums1[idx1], nums2[idx2]});

            if (idx2 + 1 != n) {
                pq.emplace(idx1, idx2 + 1);
            }
        }

        return ans;  // NRVO
    }
};

int main(int argc, char const* argv[]) { return 0; }
