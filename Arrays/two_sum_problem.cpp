// Problem - 1 (Two Sum)
// Time Complexity = O(n)
// Space Complexity = O (n)

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    map<int, int> mp;
    for (int i = 0; i < nums.size(); i++)
    {
        mp[nums[i]] = i;
    }
    for (int i = 0; i < nums.size(); i++)
    {
        int temp = target - nums[i];
        if (mp.count(temp) && mp[temp] != i)
        {
            return {i, mp[temp]};
        }
    }
    return {};
}

int main()
{
    // can be completed
}