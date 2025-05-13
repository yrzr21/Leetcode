#include <unordered_map>
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

// // 复习1
// class Solution2 {
//    public:
//     int longestConsecutive(vector<int>& nums) {
//         // 遍历数组，利用Map记录连续序列的首尾元素，及其对应的长度
//         // 对于数字x，若x-1在尾map中，则长度+1；若x+1在首map中，则长度+1
//         // 不在的不管
//         // 以下还没写完，但是我写到一半感觉太丑了...
//         unordered_map<int, int> head_map;  // ele,len
//         unordered_map<int, int> tail_map;  // ele,len

//         int ans = 0;
//         for (size_t i = 0; i < nums.size(); i++) {
//             auto head_iter = head_map.find(nums[i] + 1);
//             auto tail_iter = head_map.find(nums[i] - 1);

//             if (head_iter == head_map.end() && tail_iter == tail_map.end()) {
//                 head_map.emplace(nums[i], 1);
//                 tail_map.emplace(nums[i], 1);
//             } else if (head_iter != head_map.end() &&
//                        tail_iter != tail_map.end()) {
//                 int head = head_iter->first, head_len = head_iter->second;
//                 head_map.erase(head);
//                 tail_map.erase(head_len + head - 1);

//                 int tail = tail_iter->first, tail_len = tail_iter->second;
//                 head_map.erase(tail - tail_len + 1);
//                 tail_map.erase(tail);

//                 head_map.emplace(head, head_len + 1 + tail_len);
//                 tail_map.emplace(tail, head_len + 1 + tail_len);
//             } else if (head_iter != head_map.end()) {
//                 int len = head_iter->second, head = head_iter->first;
//                 ans = max(ans, len + 1);

//                 int tail = head + len - 1;
//                 tail_map[tail]++;

//                 head_map.erase(head_iter);
//                 head_map.emplace(head - 1, len + 1);
//             } else {
//                 int tail = tail_iter->first, len = tail_iter->second;
//                 ans = max(ans, len + 1);

//                 int head = tail - len + 1;
//                 head_map[head]++;

//                 tail_map.erase(tail_iter);
//                 tail_map.emplace(tail + 1, len + 1);
//             }
//         }

//         return ans;
//     }
// };

// 复习1
class Solution2 {
   public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return n;

        // 先把所有数都插进去，然后查看所有数：若前驱在set中，则非最长序列
        // 若不在，则计算最长序列——直到后驱不在set中
        unordered_set<int> set;
        for (int num : nums) {
            set.insert(num);
        }

        int ans = 1;
        for (int num : set) {
            if (set.find(num - 1) != set.end()) continue;

            int len = 1;
            while (set.find(++num) != set.end()) len++;
            ans = max(ans, len);
        }

        return ans;
    }
};

int main(int argc, char const* argv[]) {
    vector<int> v{100, 4, 200, 1, 3, 2};
    Solution().longestConsecutive(v);
    return 0;
}
