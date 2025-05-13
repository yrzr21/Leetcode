#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 双指针:操纵两个变量
class Solution {
   public:
    int maxArea(vector<int>& height) {
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

// 复习1
class Solution2 {
   public:
    int maxArea(vector<int>& height) {
        // i为左边界，j为右边界，闭区间
        // 计算容量，存入ans
        // 移动更矮的边界，重复上述过程。若一样矮，默认移动左边界
        int l = 0, r = height.size() - 1;
        int ans = -1;
        while (l < r) {
            ans = max(ans, capacity(height, l, r));

            if (height[l] <= height[r]) {
                l++;
            } else {
                r--;
            }
        }

        return ans;
    }

   private:
    int capacity(vector<int>& height, int l, int r) {
        return (r - l) * min(height[r], height[l]);
    }
};

int main(int argc, char const* argv[]) { return 0; }
