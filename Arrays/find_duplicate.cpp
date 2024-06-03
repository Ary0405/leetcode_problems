// Problem - 287 (Find Duplicate)
// Time Complexity - O(n)
// Space Complexity - O(n)

#include <iostream>
#include <vector>
using namespace std;

int findDuplicate(vector<int> &nums)
{
    vector<int> temp(nums.size() + 1, 0);
    for (int i = 0; i < nums.size(); i++)
    {
        if (temp[nums[i]] > 0)
        {
            return nums[i];
        }
        else
        {
            temp[nums[i]]++;
        }
    }
    return -1;
}

int main()
{
    // can be completed
}