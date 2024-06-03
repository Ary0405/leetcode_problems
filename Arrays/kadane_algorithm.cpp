// Problem - 53 (Maximum Subarray)
// Time Complexity - O(n)
// Space Complexity - O(1)

#include <iostream>
#include <vector>
using namespace std;
int maxSubArray(vector<int> &nums)
{
    int maxSum = INT_MIN;
    int n = nums.size();
    int currSum = 0;
    for (int i = 0; i < n; i++)
    {
        currSum += nums[i];
        maxSum = max(maxSum, currSum);
        if (currSum < 0)
        {
            currSum = 0;
        }
    }
    return maxSum;
}

int main()
{
    // can be completed
}