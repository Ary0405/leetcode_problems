// Problem - 229 (Majority Element 2)
// Time Complexity - O(n log(n))
// Space Complexity - O(n)

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

vector<int> majorityElement(vector<int> &nums)
{
    map<int, int> mp;
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++)
    {
        mp[nums[i]]++;
    }
    for (auto &it : mp)
    {
        if (it.second > nums.size() / 3)
        {
            ans.push_back(it.first);
        }
    }
    return ans;
}

int main()
{
    // can be completed
}