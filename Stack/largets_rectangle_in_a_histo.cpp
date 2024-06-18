// Problem - 84 (Largest Rectangle in Histogram)
// Time Complexity - O(n)
// Space Complexity - O(3n)

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

vector<int> previousSmaller(vector<int> &h)
{
    vector<int> ans(h.size());
    stack<int> s;
    for (int i = 0; i < h.size(); i++)
    {
        while (!s.empty() && h[s.top()] >= h[i])
        {
            s.pop();
        }
        if (s.empty())
        {
            ans[i] = -1;
        }
        else
        {
            ans[i] = s.top();
        }
        s.push(i);
    }
    return ans;
}

vector<int> nextSmaller(vector<int> &h)
{
    vector<int> ans(h.size());
    stack<int> s;
    for (int i = h.size() - 1; i >= 0; i--)
    {
        while (!s.empty() && h[s.top()] >= h[i])
        {
            s.pop();
        }
        if (s.empty())
        {
            ans[i] = h.size();
        }
        else
        {
            ans[i] = s.top();
        }
        s.push(i);
    }
    return ans;
}

int largestRectangleArea(vector<int> &heights)
{
    vector<int> ns = nextSmaller(heights);
    vector<int> ps = previousSmaller(heights);
    int maxArea = 0;
    for (int i = 0; i < heights.size(); i++)
    {
        int area = (ns[i] - ps[i] - 1) * heights[i];
        maxArea = max(area, maxArea);
    }
    return maxArea;
}

int main()
{
    // can be completed
}