#include <vector>
using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int u = 0; // 当前unique元素的index
        for (int i = 1; i < nums.size(); i++)
            if (nums[i] != nums[u])
                nums[++u] = nums[i];
        return u + 1;
    }
};

int main(int argc, char const* argv[]) { return 0; }
