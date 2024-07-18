// Problem - Detect Cycle in Directed Graph using BFS
// Time Complexity - O(V + E)
// Space Complexity - O(V + E)

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
using namespace std;

bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
{
    vector<vector<int>> adjList(numCourses);
    vector<int> inDegree(numCourses, 0);

    for (const auto &pre : prerequisites)
    {
        adjList[pre[1]].push_back(pre[0]);
        inDegree[pre[0]]++;
    }

    queue<int> q;
    for (int i = 0; i < numCourses; ++i)
    {
        if (inDegree[i] == 0)
        {
            q.push(i);
        }
    }

    int count = 0;
    while (!q.empty())
    {
        int course = q.front();
        q.pop();
        count++;

        for (int neighbor : adjList[course])
        {
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0)
            {
                q.push(neighbor);
            }
        }
    }

    return count == numCourses;
}

int main()
{
    // can be completed
}