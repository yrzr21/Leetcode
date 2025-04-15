#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 双指针:操纵两个变量
class Solution {
   public:
    int maxArea(vector<int> &height) {
        int l = 0, size = height.size(), r = size - 1;

        int ret = 0;
        while (l < r) {
            int capacity = min(height[l], height[r]) * (r - l);
            ret = max(capacity, ret);

            // 更新指针
            if (height[l] <= height[r])
                l++;
            else
                r--;
        }
        return ret;
    }
};

int main(int argc, char const* argv[]) { return 0; }
