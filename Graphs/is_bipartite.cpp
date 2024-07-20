// Problem - 785 (Is Graph Bipartite?)
// Time Complexity - O(V + E)
// Space Complexity - O(V)

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
using namespace std;

bool bfs_color(int node, vector<vector<int>> &graph, vector<int> &color)
{
    queue<int> q;
    q.push(node);
    color[node] = 1;

    while (!q.empty())
    {
        int current = q.front();
        q.pop();

        for (int neighbor : graph[current])
        {
            if (color[neighbor] == 0)
            {                                         
                color[neighbor] = 3 - color[current]; 
                q.push(neighbor);
            }
            else if (color[neighbor] == color[current])
            {
                return false;
            }
        }
    }
    return true;
}

bool isBipartite(vector<vector<int>> &graph)
{
    vector<int> color(graph.size(), 0);

    for (int i = 0; i < graph.size(); i++)
    {
        if (color[i] == 0)
        { 
            if (!bfs_color(i, graph, color))
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    // can be completed
}