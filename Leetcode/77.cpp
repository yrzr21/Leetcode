#include "../tools.h"

int main(int argc, char const *argv[]) { return 0; }

// 由于要求不重复，所有按升序对待
class Solution {
   public:
    vector<vector<int>> combine(int n, int k) {
        this->n = n;
        combine_sub(1, 0);
        return ans;
    }

   private:
    vector<vector<int>> ans;
    vector<int> cur;
    int n;

    // [l,r] 中 k个数组合
    // k:将枚举的index
    void combine_sub(int l, int k) {
        if (k == n) {
            ans.push_back(cur);
            return;
        }

        for (size_t i = l; i <= n; i++) {
            cur.push_back(i);
            combine_sub(i + 1, k + 1);
            cur.pop_back();
        }
    }
};