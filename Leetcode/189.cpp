#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution1
{
public:
    void rotate(vector<int> &nums, int k)
    {
        if (k == 0)
            return;
        k = k % nums.size();
        reverse(nums.begin() + nums.size() - k, nums.end());
        reverse(nums.begin(), nums.end());
        reverse(nums.begin() + k, nums.end());
    }
};

class Solution2
{
public:
    void rotate(vector<int> &nums, int k)
    {
        if (k == 0)
            return;
        vector<int> tmp(nums.size(), 0);
        for (int i = 0; i < nums.size(); i++)
            tmp[(i + k) % nums.size()] = nums[i];

        for (int i = 0; i < nums.size(); i++)
            nums[i] = tmp[i];
    }
};

class Solution3
{
public:
    void rotate(vector<int> &nums, int k)
    {
        if (k == 0)
            return;

        int cnt = 0, start = 0;
        while (cnt != nums.size())
        {
            int i = start, tmp = nums[i];
            do
            {
                swap(nums[(i + k) % nums.size()], tmp);
                i = (i + k) % nums.size();
                cnt++;
            } while (i != start && cnt != nums.size());
            start++;
        }
    }
};


int main(int argc, char const* argv[]) {
    return 0;
}
