// Problem - 56 (Merge Intervals)
// Time Complexity - O(n log(n))
// Space Complexity - O(n)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    vector<vector<int>> ans;
    if (intervals.empty())
    {
        return ans;
    }

    sort(intervals.begin(), intervals.end());

    ans.push_back({intervals[0][0], intervals[0][1]});
    int currEnd = intervals[0][1];
    int index = 0;

    for (int i = 1; i < intervals.size(); i++)
    {
        if (currEnd >= intervals[i][0])
        {
            currEnd = max(currEnd, intervals[i][1]);
        }
        else
        {
            ans[index][1] = currEnd;
            index++;
            ans.push_back({intervals[i][0], intervals[i][1]});
            currEnd = intervals[i][1];
        }
    }

    ans[index][1] = currEnd;

    return ans;
}

int main()
{
    // can be completed
}