// Problem - 74 (Search in 2D Matrix)
// Time Complexity = O(m log(n))
// Space Complexity = O (1)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        if (target <= matrix[i][matrix[i].size() - 1])
        {
            int left = 0;
            int right = matrix[i].size() - 1;
            while (left <= right)
            {
                int mid = left + (right - left) / 2;
                if (matrix[i][mid] == target)
                {
                    return true;
                }
                else if (matrix[i][mid] < target)
                {
                    left = mid + 1;
                }
                else
                {
                    right = mid - 1;
                }
            }
        }
    }
    return false;
}

int main()
{
    // can be completed
}