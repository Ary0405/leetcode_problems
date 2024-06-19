// Problem - 239 (Sliding Window Maximum)
// Time Complexity = O(n)
// Space Complexity = O (k)

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    deque<int> dq;
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++)
    {
        if (!dq.empty() && dq.front() == i - k)
        {
            dq.pop_front();
        }

        while (!dq.empty() && nums[dq.back()] < nums[i])
        {
            dq.pop_back();
        }

        dq.push_back(i);

        if (i >= k - 1)
        {
            ans.push_back(nums[dq.front()]);
        }
    }

    return ans;
}

int main()
{
    // can be completed
}