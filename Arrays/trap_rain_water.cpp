// Problem - 42 (Trapping Rain Water)
// Time Complexity = O(n)
// Space Complexity = O (1)

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int trap(vector<int> &height)
{
    int n = height.size();
    int left = 0, right = n - 1;
    int res = 0;
    int maxLeft = 0, maxRight = 0;
    while (left <= right)
    {
        if (height[left] <= height[right])
        {
            if (height[left] >= maxLeft)
            {
                maxLeft = height[left];
            }
            else
            {
                res += maxLeft - height[left];
            }
            left++;
        }
        else
        {
            if (height[right] >= maxRight)
            {
                maxRight = height[right];
            }
            else
            {
                res += maxRight - height[right];
            }
            right--;
        }
    }
    return res;
}

int main()
{
    // can be completed
}