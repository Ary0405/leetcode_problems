// Problem - Longest Subarray with 0 sum (Geeks for Geeks)
// Time Complexity = O(n)
// Space Complexity = O (n)

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <map>
using namespace std;

int maxLen(vector<int> &A, int n)
{
    unordered_map<int, int> mp;
    int sum = 0;
    int len = 0;
    for (int i = 0; i < n; i++)
    {
        sum += A[i];
        if (sum == 0)
        {
            len = max(len, i + 1);
        }
        else
        {
            if (mp.find(sum) != mp.end())
            {
                len = max(len, i - mp[sum]);
            }
            else
            {
                mp[sum] = i;
            }
        }
    }

    return len;
}

int main()
{
    // can be completed
}