#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    // 哈希表记录每个元素的 index
    // 对于相同的元素，若二者相加不等于 target，则无意义
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            if (map.contains(nums[i]) && nums[i] + nums[i] == target)
                return {map[nums[i]], i};
            map[nums[i]] = i;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != target - nums[i] && map.contains(target - nums[i]))
                return {i, map[target - nums[i]]};
        }

        return {-1, -1};
    }
};

// 复习1
class Solution2 {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;  // value,index

        for (int i = 0; i < nums.size(); i++) {
            auto iter = map.find(target - nums[i]);
            if (iter != map.end()) return {(*iter).second, i};

            // not in map
            map.emplace(nums[i], i);
        }

        return {-1, -1};
    }
};

int main(int argc, char const* argv[]) { return 0; }
