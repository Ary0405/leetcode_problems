// Problem - 26 (Remove Duplicates from Sorted Array)
// Time Complexity - O(n log(n))
// Space Complexity - O(n)

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int removeDuplicates(vector<int> &nums)
{
    unordered_map<int, int> mp;

    for (int i = 0; i < nums.size(); i++)
    {
        mp[nums[i]]++;
    }

    map<int, int> ordered(mp.begin(), mp.end());
    int y = 0;

    for (auto it : ordered)
    {
        nums[y] = it.first;
        y++;
    }

    return y;
}

int main()
{
    // can be completed
}