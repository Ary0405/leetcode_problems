// Problem - Floyd Warshall Algorithm (Geeks for Geeks)
// Time Complexity - O(V ^ 3)
// Space Complexity - O(V)

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
using namespace std;

void shortest_distance(vector<vector<int>> &matrix)
{

    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix.size(); j++)
        {
            if (matrix[i][j] == -1)
            {
                matrix[i][j] = 1e9;
            }
            if (i == j)
            {
                matrix[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix.size(); j++)
        {
            for (int k = 0; k < matrix.size(); k++)
            {
                matrix[j][k] = min(matrix[j][k], matrix[j][i] + matrix[i][k]);
            }
        }
    }

    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix.size(); j++)
        {
            if (matrix[i][j] == 1e9)
            {
                matrix[i][j] = -1;
            }
        }
    }
}

int main()
{
    // can be completed
}