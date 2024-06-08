// Problem - 56 (Max Consecutive Ones)
// Time Complexity - O(n)
// Space Complexity - O(1)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findMaxConsecutiveOnes(vector<int> &nums)
{
    int cnt = 0;
    int maxCnt = INT_MIN;

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 1)
        {
            cnt++;
        }
        else
        {
            maxCnt = max(maxCnt, cnt);
            cnt = 0;
        }
    }

    if (cnt != 0)
    {
        maxCnt = max(cnt, maxCnt);
    }

    return maxCnt;
}

int main()
{
    // can be completed
}