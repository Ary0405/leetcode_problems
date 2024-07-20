// Problem - Bipartite Graph Using DFS
// Time Complexity - O(V + E)
// Space Complexity - O(V)

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
using namespace std;

bool dfs_color(int node, vector<vector<int>> &graph, vector<int> &color)
{
    stack<int> st;
    color[node] = 1;
    st.push(node);

    while (!st.empty())
    {
        int top = st.top();
        st.pop();

        for (int neighbor : graph[top])
        {
            if (color[neighbor] == 0)
            {
                color[neighbor] = 3 - color[top];
                st.push(neighbor);
            }
            else if (color[neighbor] == color[top])
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
            if (!dfs_color(i, graph, color))
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