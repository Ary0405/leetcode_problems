// Problem - 200 (Number of Islands)
// Time Complexity - O(M*N)
// Space Complexity - O(M*N)

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
using namespace std;

void dfs(int i, int j, vector<vector<char>> &grid, vector<vector<bool>> &visited, vector<pair<int, int>> &v)
{
    visited[i][j] = true;

    int changeRow[4] = {-1, 0, 1, 0};
    int changeCol[4] = {0, 1, 0, -1};

    v.push_back({i, j});

    for (int k = 0; k < 4; k++)
    {
        int nR = i + changeRow[k];
        int nC = j + changeCol[k];
        if (nR >= 0 && nR < grid.size() && nC >= 0 && nC < grid[0].size() && !visited[nR][nC] && grid[nR][nC] == '1')
        {
            dfs(nR, nC, grid, visited, v);
        }
    }
}

int numIslands(vector<vector<char>> &grid)
{
    vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
    stack<vector<pair<int, int>>> st;

    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[i].size(); j++)
        {
            if (visited[i][j] == 0 && grid[i][j] == '1')
            {
                vector<pair<int, int>> v;
                dfs(i, j, grid, visited, v);
                cout << v.size() << endl;
                st.push(v);
            }
        }
    }

    return st.size();
}

int main()
{
    // can be completed
}