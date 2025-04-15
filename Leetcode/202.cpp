#include <unordered_set>
using namespace std;

class Solution {
   private:
    int convert(int n) {
        int ret = 0;
        while (n > 0) {
            ret += (n % 10) * (n % 10);
            n /= 10;
        }
        return ret;
    }

   public:
    bool isHappy(int n) {
        unordered_set<int> set;
        while (!set.contains(n)) {
            set.insert(n);
            n = convert(n);
            if (n == 1) return true;
        }
        return false;
    }
};

int main(int argc, char const *argv[]) {
    Solution().isHappy(7);
    return 0;
}
