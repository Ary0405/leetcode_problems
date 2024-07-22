// Problem - Prims Algorithm (Geeks for Geeks)
// Time Complexity - O((V+E)logV)
// Space Complexity - O(V + E)

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
using namespace std;

struct compare
{
    bool operator()(const pair<int, int> &p1, const pair<int, int> &p2)
    {
        return p1.second > p2.second;
    }
};

int spanningTree(int V, vector<vector<int>> adj[])
{
    vector<bool> vis(V, false);
    priority_queue<vector<int>, vector<vector<int>>, compare> minHeap;

    vis[0] = true;
    for (auto &edge : adj[0])
    {
        minHeap.push({0, edge[0], edge[1]});
    }

    int mstWeight = 0;

    while (!minHeap.empty())
    {
        vector<int> top = minHeap.top();
        minHeap.pop();

        int u = top[0], v = top[1], weight = top[2];

        if (vis[v])
        {
            continue;
        }

        vis[v] = true;
        mstWeight += weight;

        for (auto &edge : adj[v])
        {
            if (!vis[edge[0]])
            {
                minHeap.push({v, edge[0], edge[1]});
            }
        }
    }

    return mstWeight;
}

int main()
{
    // can be completed
}