// Problem - Subset Sum (Geeks for Geeks)
// Time Complexity = O(2^n log(2^n))
// Space Complexity = O (2^n)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void helper(vector<int> arr, vector<int> &ans, int n, int ind, int sum)
{
    if (ind == n)
    {
        ans.push_back(sum);
        return;
    }

    // element is picked
    helper(arr, ans, n, ind + 1, sum + arr[ind]);

    // element is not picked
    helper(arr, ans, n, ind + 1, sum);
}

vector<int> subsetSums(vector<int> arr, int n)
{
    vector<int> ans;
    helper(arr, ans, n, 0, 0);
    sort(ans.begin(), ans.end());
    return ans;
}

int main()
{
    // can be completed
}