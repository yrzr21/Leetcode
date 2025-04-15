#include "../tools.h"

class Solution {
   public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());  // 方便剪枝
        combine(candidates, 0, target);

        return ans;
    }

   private:
    vector<int> cur;
    vector<vector<int>> ans;

    // candidates[i] 表示待选择的数字
    void combine(vector<int>& candidates, int i, int target) {
        if (target == 0) {
            ans.push_back(cur);
            return;
        }
        if (i == candidates.size() || target < candidates[i]) return;

        int candidate = candidates[i];
        // 0次或多次选择
        combine(candidates, i + 1, target);
        for (size_t j = 1; j <= target / candidate; j++) {
            cur.push_back(candidate);
            combine(candidates, i + 1, target - j * candidate);
        }

        // pop
        for (size_t j = 1; j <= target / candidate; j++) {
            cur.pop_back();
        }
    }
};

int main(int argc, char const* argv[]) {
    vector<int> v{2, 3, 6, 7};
    Solution().combinationSum(v, 7);
    return 0;
}
