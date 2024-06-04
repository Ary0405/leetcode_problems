// Problem - 62 (Unique Paths)
// Time Complexity - O(mn)
// Space Complexity - O(mn)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int helper(int m, int n, vector<vector<int>> &dp, int i, int j)
{
    if (i == m - 1 && j == n - 1)
    {
        return 1;
    }
    if (i >= m || j >= n)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int ans = helper(m, n, dp, i + 1, j) + helper(m, n, dp, i, j + 1);
    dp[i][j] = ans;
    return ans;
}
int uniquePaths(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return helper(m, n, dp, 0, 0);
}

int main()
{
    // can be completed
}