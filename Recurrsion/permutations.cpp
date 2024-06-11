// Problem - 46 (Permutations)
// Time Complexity = O(n*n!)
// Space Complexity = O (n)

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

void helper(vector<int> nums, vector<vector<int>> &ans, int index)
{
    if (index == nums.size())
    {
        ans.push_back(nums);
        return;
    }
    for (int i = index; i < nums.size(); i++)
    {
        swap(nums[index], nums[i]);
        helper(nums, ans, index + 1);
        swap(nums[index], nums[i]);
    }
}

vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> ans;
    helper(nums,ans,0);
    return ans;
}

int main()
{
    // can be completed
}