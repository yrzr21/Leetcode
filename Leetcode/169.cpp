#include <vector>
using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int candidate, cnt = 0;
        for (int &i : nums)
        {
            if (cnt == 0)
            {
                candidate = i;
                cnt = 1;
            }
            else if (candidate == i)
                cnt++;
            else
                cnt--;
        }
        return candidate;
    }
};
int main(int argc, char const* argv[]) {
    return 0;
}
