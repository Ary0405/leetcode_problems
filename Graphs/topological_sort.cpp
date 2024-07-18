// Problem - Topological Order (Geeks for Geeks)
// Time Complexity - O(V + E)
// Space Complexity - O(V)

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
using namespace std;

vector<int> topoSort(int V, vector<int> adj[])
{
    vector<int> inDegree(V, 0);
    vector<int> topoOrder;

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < adj[i].size(); j++)
        {
            inDegree[adj[i][j]]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < V; i++)
    {
        if (inDegree[i] == 0)
        {
            q.push(i);
        }
    }

    while(!q.empty())
    {
        int f = q.front();
        q.pop();
        topoOrder.push_back(f);

        for(int neigh : adj[f])
        {
            inDegree[neigh]--;
            if(inDegree[neigh] == 0)
            {
                q.push(neigh);
            }
        }
    }

    return topoOrder;
}

int main()
{
    // can be completed
}