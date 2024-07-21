// Problem - Bellman Ford Algorithm (Geeks for Geeks)
// Time Complexity - O(V * E)
// Space Complexity - O(V)

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
using namespace std;

vector<int> bellman_ford(int V, vector<vector<int>> &edges, int S)
{
    vector<int> distances(V, 100000000);
    distances[S] = 0;

    for (int i = 0; i < V - 1; i++)
    {
        for (int j = 0; j < edges.size(); j++)
        {
            distances[edges[j][1]] = min(distances[edges[j][1]], distances[edges[j][0]] + edges[j][2]);
        }
    }

    for (int j = 0; j < edges.size(); j++)
    {
        if (distances[edges[j][0]] + edges[j][2] < distances[edges[j][1]])
        {
            return {-1};
        }
    }

    return distances;
}

int main()
{
    // can be completed
}