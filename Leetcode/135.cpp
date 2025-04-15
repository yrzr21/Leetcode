#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int candy(vector<int>& ratings) {
        int size = ratings.size();
        if (size == 1) return 1;

        // 小于等于两边的糖果=1
        // 只大于一边的糖果=该边+1
        // 大于两边的=两边中最大的+1

        vector<int> candy_cnt(size, 0);
        // 初始化端点
        candy_cnt[0] = ratings[0] <= ratings[1] ? 1 : 2;
        candy_cnt[size - 1] = ratings[size - 1] <= ratings[size - 2] ? 1 : 2;
        if (size == 2) return candy_cnt[0] + candy_cnt[1];

        // 从左往右遍历，除了上述规则，只大于左边的糖果=左+1
        for (size_t i = 1; i < size - 1; i++) {
            if (ratings[i] <= ratings[i - 1] && ratings[i] <= ratings[i + 1])
                candy_cnt[i] = 1;
            else if (ratings[i] > ratings[i - 1] &&
                     ratings[i] <= ratings[i + 1])
                candy_cnt[i] = candy_cnt[i - 1] + 1;
        }

        // 从右往左遍历，除了上述规则，只大于右边的糖果=右+1
        // 大于两边的必定初始化了左边，所以可以使用第三个规则
        for (size_t i = size - 2; i > 0; i--) {
            if (ratings[i] <= ratings[i - 1] && ratings[i] <= ratings[i + 1])
                candy_cnt[i] = 1;
            else if (ratings[i] <= ratings[i - 1] &&
                     ratings[i] > ratings[i + 1])
                candy_cnt[i] = candy_cnt[i - 1] + 1;
            else
                candy_cnt[i] = 1 + max(candy_cnt[i - 1], candy_cnt[i + 1]);
        }

        // 两次遍历可初始化，曲线底部、非严格单调增的部分、非严格单调减的部分....也即初始化全部曲线
        // 统计所有糖果
        int cnt = 0;
        for (size_t i = 0; i < size; i++) cnt += candy_cnt[i];

        return cnt;
    }
};
int main(int argc, char const* argv[]) {
    return 0;
}
