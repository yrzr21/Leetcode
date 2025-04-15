#include <vector>
using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.size() == 1)
            return 1;
        int u = 1; // 最后一个至多出现两次的元素下标
        for (int i = 2; i < nums.size(); i++)
        {
            if (nums[i] != nums[u] || nums[i] != nums[u - 1])
                nums[++u] = nums[i];
        }
        return u + 1;
    }
};
int main(int argc, char const* argv[]) {
    return 0;
}
