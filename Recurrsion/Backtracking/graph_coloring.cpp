// Problem - Graph Coloring Problem (Geeks for Geeks)
// Time Complexity = O(n^m)
// Space Complexity = O(n)

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool isPossible(int node, int color[], bool graph[101][101], int n, int col)
{
    for (int k = 0; k < n; k++)
    {
        if (k != node && graph[k][node] == 1 && color[k] == col)
        {
            return false;
        }
    }
    return true;
}

bool solve(int node, int m, int n, int col[], bool graph[101][101])
{
    if (node == n)
    {
        return true;
    }

    for (int i = 1; i <= m; i++)
    {
        if (isPossible(node, col, graph, n, i))
        {
            col[node] = i;
            if (solve(node + 1, m, n, col, graph))
            {
                return true;
            }
            col[node] = 0;
        }
    }

    return false;
}

bool graphColoring(bool graph[101][101], int m, int N)
{
    int color[N] = {0};
    if (solve(0, m, N, color, graph))
    {
        return true;
    }
    return false;
}

int main()
{
    // can be completed
}