// Problem - 50 (Pow(x,n))
// Time Complexity = O(log(n))
// Space Complexity = O (1)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

double myPow(double x, int n)
{
    double ans = 1;
    long long raise = n;
    if (raise < 0)
    {
        raise = -1 * raise;
    }
    while (raise)
    {
        if (raise % 2)
        {
            ans = ans * x;
            raise = raise - 1;
        }
        else
        {
            x = x * x;
            raise = raise / 2;
        }
    }
    if (n < 0)
        return ((double)1 / (double)ans);
    return ans;
}

int main()
{
    // can be completed
}