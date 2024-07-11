// Problem - Breadth First Search of a Graph (Geeks for Geeks)
// Time Complexity - O(V+E)
// Space Complexity - O(V)

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
using namespace std;

void bfs(int node, vector<int> adj[], vector<bool> &visited, vector<int> &result)
{
    queue<int> q;
    q.push(node);
    visited[node] = true;

    while (!q.empty())
    {
        int top = q.front();
        result.push_back(top);
        q.pop();

        for (int i = 0; i < adj[top].size(); ++i)
        {
            if (!visited[adj[top][i]])
            {
                q.push(adj[top][i]);
                visited[adj[top][i]] = true;
            }
        }
    }
}

vector<int> bfsOfGraph(int V, vector<int> adj[])
{
    vector<bool> visited(V, false);
    vector<int> result;

    for (int i = 0; i < V; ++i)
    {
        if (!visited[i])
        {
            bfs(i, adj, visited, result);
        }
    }

    return result;
}

int main()
{
    // can be completed
}