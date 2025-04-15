#include <algorithm>
#include <iostream>
#include <stack>
#include <utility>
#include <vector>
using namespace std;

class Solution {
   private:
    // 调用者需保证左右均大于bottom
    int calHeight(int& bottom, pair<int, int>& left, pair<int, int>& right) {
        return (min(left.first, right.first) - bottom) *
               (right.second - left.second - 1);
    }

   public:
    // 重复以下过程：
    // 若栈为空且高度不为0，或高度<=栈顶高度，入栈
    // 若高度大于栈顶高度，栈顶为底部，找到一个>栈底部的，计算雨水量，直到高度<=栈顶高度或栈为空
    // 期间维护长度
    // 结束遍历：即抵达终点
    int trap(vector<int>& height) {
        stack<pair<int, int>> left;
        int rain = 0;
        int size = height.size();

        for (int i = 0; i < size; i++) {
            pair<int, int> right{height[i], i};

            if (left.empty() || right.first < left.top().first) {
                left.push(move(right));
                continue;
            } else if (right.first < left.top().first)
                continue;

            // 计算雨水量
            int bottom = left.top().first;
            while (!left.empty() && right.first > bottom) {
                // 底部
                while (!left.empty() && left.top().first == bottom) left.pop();
                if (left.empty()) break;

                rain += calHeight(bottom, left.top(), right);

                bottom = left.top().first;
                cout << "i=" << i << " rain=" << rain << endl;
            }

            left.push(move(right));
        }

        return rain;
    }
};

int main(int argc, char const* argv[]) {
    vector<int> v{4, 2, 0, 3, 2, 5};
    cout << Solution().trap(v);
    return 0;
}
