#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();
        unordered_set<int> set;
        for (const int& num : nums) set.insert(num);

        // 只在连续序列尾部计算长度
        int maxlen = 1;
        for (int num : set) {
            if (set.find(num + 1) != set.end()) continue;

            int len = 1;
            while (set.find(--num) != set.end()) len++;
            if (len > maxlen) maxlen = len;
        }
        return maxlen;
    }
};

int main(int argc, char const* argv[]) {
    vector<int> v{100, 4, 200, 1, 3, 2};
    Solution().longestConsecutive(v);
    return 0;
}
