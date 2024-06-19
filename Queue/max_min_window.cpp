// Problem - Maximum of minimum for every window size (Coding Ninjas)
// Time Complexity = O(n^2)
// Space Complexity = O (n)

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

vector<int> maxSlidingWindow(vector<int> &nums, int n)
{
    vector<int> ans;
    for (int j = 1; j <= n; j++)
    {
        int k = j;
        int maxE = INT_MIN;
        deque<int> dq;
        for (int i = 0; i < n; i++)
        {
            if (!dq.empty() && dq.front() == i - k)
            {
                dq.pop_front();
            }

            while (!dq.empty() && nums[dq.back()] > nums[i])
            {
                dq.pop_back();
            }

            dq.push_back(i);

            if (i >= k - 1)
            {
                maxE = max(nums[dq.front()], maxE);
            }
        }

        ans.push_back(maxE);
    }

    return ans;
}

int main()
{
    // can be completed
}