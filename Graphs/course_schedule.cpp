// Problem - 207 (Course Schedule)
// Time Complexity - O(V + E)
// Space Complexity - O(V + E)

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
using namespace std;

bool dfs(int course, vector<vector<int>> &adjList, vector<int> &visited, vector<int> &path)
{
    visited[course] = 1; 
    path[course] = 1;

    for (int next : adjList[course])
    {
        if (path[next])
        { 
            return true;
        }
        if (!visited[next])
        { 
            if (dfs(next, adjList, visited, path))
            {
                return true;
            }
        }
    }

    path[course] = 0;
    return false;
}

bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
{
    vector<vector<int>> adjList(numCourses);
    for (const auto &pre : prerequisites)
    {
        adjList[pre[1]].push_back(pre[0]);
    }

    vector<int> visited(numCourses, 0);
    vector<int> path(numCourses, 0);

    for (int i = 0; i < numCourses; ++i)
    {
        if (!visited[i])
        {
            if (dfs(i, adjList, visited, path))
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