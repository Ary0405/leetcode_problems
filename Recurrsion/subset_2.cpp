// Problem - 90 (Subsets II)
// Time Complexity = O((2^n)n)
// Space Complexity = O ((2^n)n)

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

void helper(vector<int> nums, vector<vector<int>> &ans, int ind, vector<int> temp)
{
    ans.push_back(temp);
    for (int i = ind; i < nums.size(); i++)
    {
        if (i != ind && nums[i] == nums[i - 1])
        {
            continue;
        }
        temp.push_back(nums[i]);
        helper(nums, ans, i + 1, temp);
        temp.pop_back();
    }
}

vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    helper(nums, ans, 0, {});
    return ans;
}

int main()
{
    // can be completed
}