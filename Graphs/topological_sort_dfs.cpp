// Problem - Topological Order using DFS (Geeks for Geeks)
// Time Complexity - O(V + E)
// Space Complexity - O(V)

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
using namespace std;

void findTopoSort(int node, vector<int> &vis, stack<int> &st, vector<int> adj[])
{
    vis[node] = 1;

    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            findTopoSort(it, vis, st, adj);
        }
    }
    st.push(node);
}

vector<int> topoSort(int V, vector<int> adj[])
{
    vector<int> topoOrder;
    vector<int> visited(V, 0);

    stack<int> st;

    for(int i = 0 ; i < V ; i++)
    {
        if (!visited[i])
        {
            findTopoSort(i, visited, st, adj);
        }
    }

    while(!st.empty()) 
    {
        topoOrder.push_back(st.top());
        st.pop();
    }

    return topoOrder;
}

int main()
{
    // can be completed
}