#include <vector>
using namespace std;

class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int w = 0; // next to write
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] != val)
                nums[w++] = nums[i];
        return w;
    }
};

int main(int argc, char const* argv[]) { return 0; }
