#include "../tools.h"

class Solution {
   public:
    int findMaximizedCapital(int k, int w, vector<int>& profits,
                             vector<int>& capital) {
        // 先根据资本排个序，把所有能做的利润都压入大根堆，每次取最大的做，增值资本，重复

        int n = profits.size();
        vector<pair<int, int>> arr;
        for (size_t i = 0; i < n; i++) {
            arr.emplace_back(capital[i], profits[i]);
        }
        sort(arr.begin(), arr.end());

        priority_queue<int> pq;
        int cur = 0;
        for (size_t i = 0; i < k; i++) {
            // 挑一个当前资本能做的
            while (cur < n && arr[cur].first <= w) {
                pq.push(arr[cur++].second);
            }

            if (pq.empty()) break;
            w += pq.top();
            pq.pop();
        }

        return w;
    }
};

int main(int argc, char const* argv[]) { return 0; }
