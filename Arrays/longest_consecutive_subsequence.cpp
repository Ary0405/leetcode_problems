// Problem - 128 (Longest Consecutive Subsequence)
// Time Complexity = O(n)
// Space Complexity = O (n)

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

int longestConsecutive(vector<int> &nums)
{
    int n = nums.size();
    if (n == 0)
    {
        return 0;
    }
    int count = 1;
    unordered_set<int> st;
    for (int i = 0; i < n; i++)
    {
        st.insert(nums[i]);
    }
    for (auto it : st)
    {
        if (st.find(it - 1) == st.end())
        {
            int temp = 1;
            int x = it;
            while (st.find(x + 1) != st.end())
            {
                x = x + 1;
                temp = temp + 1;
            }
            count = max(temp, count);
        }
    }
    return count;
}

int main()
{
    // can be completed
}