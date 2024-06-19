// Problem - 994 (Rotting Oranges)
// Time Complexity = O(n*m)
// Space Complexity = O (n*m)

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int orangesRotting(vector<vector<int>> &grid)
{
    int vis[grid.size()][grid[0].size()];
    queue<pair<pair<int, int>, int>> q;

    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (grid[i][j] == 2)
            {
                vis[i][j] = 2;
                q.push({{i, j}, 0});
            }
            else
            {
                vis[i][j] = 0;
            }
        }
    }

    int changeRow[4] = {-1, 0, 1, 0};
    int changeCol[4] = {0, 1, 0, -1};
    int tMax = 0;

    while (!q.empty())
    {
        int r = q.front().first.first;
        int c = q.front().first.second;

        int t = q.front().second;

        tMax = max(t, tMax);

        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nRow = r + changeRow[i];
            int nCol = c + changeCol[i];

            if (nRow >= 0 && nRow < grid.size() && nCol >= 0 && nCol < grid[0].size() && vis[nRow][nCol] != 2 && grid[nRow][nCol] == 1)
            {
                q.push({{nRow, nCol}, t+1});
                vis[nRow][nCol] = 2;
            }
        }
    }

    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (grid[i][j] == 1 && vis[i][j] != 2)
            {
                return -1;
            }
        }
    }

    return tMax;
}

int main()
{
    // can be completed
}