// Problem - 169 (Majority Element)
// Time Complexity - O(n log(n))
// Space Complexity - O(n)

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int majorityElement(vector<int> &nums)
{
    map<int, int> mp;
    for (int i = 0; i < nums.size(); i++)
    {
        mp[nums[i]]++;
    }
    for (auto &it : mp)
    {
        if (it.second > nums.size() / 2)
        {
            return it.first;
        }
    }
    return -1;
}

int main()
{
    // can be completed
}