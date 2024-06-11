// Problem - 39 (Combination Sum)
// Time Complexity = O((2^n)k)
// Space Complexity = O (k)

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

void helper(vector<int> &candidates, int target, vector<int> &temp, vector<vector<int>> &ans, int index)
{
    if (index == candidates.size())
    {
        if (target == 0)
        {
            ans.push_back(temp);
        }
        return;
    }
    if (candidates[index] <= target)
    {
        temp.push_back(candidates[index]);
        helper(candidates, target - candidates[index], temp, ans, index);
        temp.pop_back();
    }
    helper(candidates, target, temp, ans, index + 1);
}
vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<vector<int>> ans;
    vector<int> temp;
    helper(candidates, target, temp, ans, 0);
    return ans;
}

int main()
{
    // can be completed
}