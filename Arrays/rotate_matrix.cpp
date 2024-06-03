// Problem - 48 (Rotate Image)
// Time Complexity - O(n^2)
// Space Complexity - O(1)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void rotate(vector<vector<int>> &matrix)
{
    int n = matrix.size();

    for (int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < i ; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    for(int i = 0 ; i < n ; i++)
    {
        reverse(matrix.begin(), matrix.end());
    }

    return;
}

int main()
{
    // can be completed
}