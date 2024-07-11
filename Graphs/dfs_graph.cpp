// Problem - Depth First Search of a Graph (Geeks for Geeks)
// Time Complexity - O(V+E)
// Space Complexity - O(V)

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
using namespace std;

void dfs(int node, vector<int> adj[], vector<bool> &visited, vector<int> &result)
{
    stack<int> st;
    st.push(node);

    while (!st.empty())
    {
        int top = st.top();
        st.pop();

        if (!visited[top])
        {
            visited[top] = true;
            result.push_back(top);

            for (int i = adj[top].size() - 1; i >= 0; --i)
            {
                if (!visited[adj[top][i]])
                {
                    st.push(adj[top][i]);
                }
            }
        }
    }
}

vector<int> dfsOfGraph(int V, vector<int> adj[])
{
    vector<bool> visited(V, false);
    vector<int> result;

    for (int i = 0; i < V; ++i)
    {
        if (!visited[i])
        {
            dfs(i, adj, visited, result);
        }
    }

    return result;
}

int main()
{
    // can be completed
}