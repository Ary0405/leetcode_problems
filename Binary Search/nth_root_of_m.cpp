// Problem - Nth root of m (Coding Ninjas)
// Time Complexity = O(n log(m))
// Space Complexity = O (1)

#include <iostream>
using namespace std;

int helper(int n, int m, int mid)
{
    int ans = 1;
    for (int i = 1; i < n; i++)
    {
        ans = ans * mid;
        if (ans > m)
        {
            return 2;
        }
    }
    if (ans == m)
    {
        return 1;
    }

    return 0;
}

int NthRoot(int n, int m)
{
    int lo = 1;
    int hi = m;
    int mid;

    while (lo < hi)
    {
        mid = lo + (hi - lo) / 2;
        int h = helper(n, m, mid);
        if (h == 1)
        {
            return mid;
        }
        else if (h == 2)
        {
            hi = mid - 1;
        }
        else
        {
            lo = mid + 1;
        }
    }

    return -1;
}

int main()
{
    // can be completed
}