// Problem - 40 (Combination Sum 2)
// Time Complexity = O((2^n)n)
// Space Complexity = O (n)

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

void helper(vector<int> &candidates, int target, vector<int> &temp, vector<vector<int>> &ans, int index)
{
    if (target == 0)
    {
        ans.push_back(temp);
        return;
    }
    for (int i = index; i < candidates.size(); i++)
    {
        if (i > index && candidates[i] == candidates[i - 1])
        {
            continue;
        }
        if (candidates[i] > target)
        {
            break;
        }
        temp.push_back(candidates[i]);
        helper(candidates, target - candidates[i], temp, ans, i + 1);
        temp.pop_back();
    }
}
vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    vector<vector<int>> ans;
    vector<int> temp;
    sort(candidates.begin(), candidates.end());
    helper(candidates, target, temp, ans, 0);
    return ans;
}

int main()
{
    // can be completed
}