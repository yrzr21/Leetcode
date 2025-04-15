#include <string>
#include <vector>
using namespace std;

class Solution {
   private:
    string construct_string(int l, int r) {
        if (l == r) return to_string(l);
        return to_string(l) + "->" + to_string(r);
    }

   public:
    vector<string> summaryRanges(vector<int>& nums) {
        if (nums.size() == 0) return {};
        vector<string> ret;
        int l = 0;
        for (int r = 1; r < nums.size(); r++) {
            if (nums[r] == nums[r - 1] + 1) continue;
            ret.emplace_back(construct_string(nums[l], nums[r - 1]));
            l = r;
        }
        ret.emplace_back(construct_string(nums[l], nums[nums.size() - 1]));

        return ret;
    }
};
int main(int argc, char const* argv[]) {
    return 0;
}
