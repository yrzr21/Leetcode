#include "../tools.h"

class MedianFinder {
   public:
    MedianFinder() {}

    void addNum(int num) {
        if (!le.empty() && num > le.top()) {
            ge.push(num);
            if (ge.size() > le.size()) {
                le.push(ge.top());
                ge.pop();
            }
        } else {
            le.push(num);
            if (le.size() > ge.size() + 1) {
                ge.push(le.top());
                le.pop();
            }
        }
    }

    double findMedian() {
        // if (size == 0) return -1;
        if (le.size() == ge.size()) return (le.top() + ge.top()) / 2.0;

        // odd
        return le.top();
    }

   private:
    priority_queue<int> le;  // 优先放入le，总>=ge大小
    priority_queue<int, vector<int>, greater<int>> ge;
};

int main(int argc, char const *argv[]) { return 0; }
