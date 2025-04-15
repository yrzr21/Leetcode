#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class RandomizedSet {
   private:
    unordered_map<int, int> rs;  // <val, index>
    vector<int> nums;

   public:
    RandomizedSet() { srand((unsigned)time(NULL)); }

    bool insert(int val) {
        if (rs.count(val)) return false;
        rs[val] = nums.size();
        nums.emplace_back(val);
        return true;
    }

    bool remove(int val) {
        if (!rs.count(val)) return false;

        int i = rs[val];
        int last = nums.back();

        if (i != nums.size() - 1) {
            rs[last] = i;
            nums[i] = last;
        }
        rs.erase(val);
        nums.pop_back();
        return true;
    }

    int getRandom() {
        int i = rand() % nums.size();
        return nums[i];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
int main(int argc, char const* argv[]) {
    return 0;
}
