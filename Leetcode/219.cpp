#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        for (size_t i = 0; i < nums.size(); i++) {
            if (map.contains(nums[i]) && i - map[nums[i]] <= k) return true;
            map[nums[i]] = i;
        }
        return false;
    }
};
int main(int argc, char const* argv[]) {
    return 0;
}
