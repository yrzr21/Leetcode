#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int hIndex(vector<int>& citations) {
        // h<=n

        // 一种暴力解法：找到最高引用，不断-1是否满足h指数
        // 改良：二分
        // 满足h：citations[size-h]>h，若=则直接返回，
        sort(citations.begin(), citations.end(), greater<int>());

        int l = 0, r = citations.size(), n = citations.size();
        while (l <= r) {
            int mid = (l + r) / 2;

            if (mid == 0 || citations[mid - 1] >= mid)
                l = mid + 1;
            else if (citations[mid - 1] < mid)
                r = mid - 1;
        }
        return l - 1;
    }
};
int main(int argc, char const* argv[]) {
    return 0;
}
