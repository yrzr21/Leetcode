#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int maxProfit(vector<int> &prices) {
        int cnt = 0;
        for (int i = 0; i < prices.size() - 1; i++) {
            int start = i;
            while (i < prices.size() - 1 && prices[i] < prices[i + 1]) i++;
            if (i == prices.size()) break;
            cnt += (prices[i] - prices[start]);
        }
        return cnt;
    }
};
int main(int argc, char const* argv[]) {
    return 0;
}
