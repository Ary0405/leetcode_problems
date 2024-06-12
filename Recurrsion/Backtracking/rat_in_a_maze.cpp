// Problem - Rat in a Maze (Geeks for Geeks)
// Time Complexity = O(4^(n^2))
// Space Complexity = O(n^2)

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool isSafe(vector<vector<int>> &m, vector<vector<bool>> &visited, int n, int i, int j)
{
    if (i >= 0 && i < n && j >= 0 && j < n && m[i][j] == 1 && !visited[i][j])
    {
        return true;
    }
    return false;
}

void solve(vector<string> &ans, vector<vector<int>> &m, vector<vector<bool>> &visited, int n, int i, int j, string temp)
{
    if (i == n - 1 && j == n - 1)
    {
        ans.push_back(temp);
        return;
    }

    visited[i][j] = true;

    // checking up
    if (isSafe(m, visited, n, i - 1, j))
    {
        solve(ans, m, visited, n, i - 1, j, temp + 'U');
    }

    // checking down
    if (isSafe(m, visited, n, i + 1, j))
    {
        solve(ans, m, visited, n, i + 1, j, temp + 'D');
    }

    // checking right
    if (isSafe(m, visited, n, i, j + 1))
    {
        solve(ans, m, visited, n, i, j + 1, temp + 'R');
    }

    // checking left
    if (isSafe(m, visited, n, i, j - 1))
    {
        solve(ans, m, visited, n, i, j - 1, temp + 'L');
    }

    visited[i][j] = false;
}

vector<string> findPath(vector<vector<int>> &m, int n)
{
    vector<string> ans;
    if (m[0][0] == 0 || m[n - 1][n - 1] == 0)
    {
        return ans; 
    }
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    solve(ans, m, visited, n, 0, 0, "");
    return ans;
}

int main()
{
    // can be completed
}