
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
   public:
    // 双指针暴力枚举
    // 若numbers[l]+numbers[r]>target,r--
    // <,l++
    // =,返回
    // 依据题意一定存在解,且为两个数字
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, size = numbers.size(), r = size - 1;
        while (l < r) {
            if (numbers[l] + numbers[r] == target)
                return {l + 1, r + 1};
            else if (numbers[l] + numbers[r] > target)
                r--;
            else
                l++;
        }
        return {-1, -1};
    }

    // 这一步不可能
};
int main(int argc, char const* argv[]) {
    return 0;
}
