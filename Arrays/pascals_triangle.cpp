// Problem - 118 (Pascals Triangle)
// Time Complexity = O(n^2)
// Space Complexity = O (n^2)

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> ans;
    for(int i = 0 ; i < numRows ; i++)
    {
        for(int j = 0 ; j <= i ; j++)
        {
            if(j == 0 || j == i)
            {
                ans[i].push_back(1);
            }
            else
            {
                ans[i].push_back(ans[i-1][j] + ans[i-1][j-1]);
            }
        }
    }
    return ans;
}

int main()
{
    // can be completed
}