// Problem - Dijkstra Algorithm (Geeks for Geeks)
// Time Complexity - O((V+E)logV)
// Space Complexity - O(V + E)

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
using namespace std;

vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    vector<int> distances(V, INT_MAX);
    distances[S] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, S});

    while (!pq.empty())
    {
        int u = pq.top().second;
        int dist = pq.top().first;
        pq.pop();

        if (dist > distances[u])
            continue;

        for (auto edge : adj[u])
        {
            int v = edge[0];
            int weight = edge[1];

            if (dist + weight < distances[v])
            {
                distances[v] = dist + weight;
                pq.push({distances[v], v});
            }
        }
    }

    return distances;
}

int main()
{
    // can be completed
}