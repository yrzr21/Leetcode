#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        // 贪心
        int start = 0;
        int n = gas.size();
        while (start != n) {
            int i = start;  // 最远可抵达位置
            int remain = gas[start] - cost[start];
            while (remain >= 0) {
                i = (i + 1) % n;
                remain = remain + gas[i] - cost[i];
            }
            // [start,i)任意加油站出发均无法环路一周
            if (i != start)
                start = i + 1;
            else
                return start;
        }
        return -1;
    }
};
int main(int argc, char const* argv[]) {
    return 0;
}
