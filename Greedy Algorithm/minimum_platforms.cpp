// Problem - Minimum platforms (Geeks for Geeks)
// Time Complexity = O(n log(n))
// Space Complexity = O (1)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findPlatform(int arr[], int dep[], int n)
{
    sort(arr, arr + n);
    sort(dep, dep + n);

    int i = 1, j = 0;
    int plfNeeded = 1;
    int maxPlf = 1;
    while (i < n && j < n)
    {
        if (arr[i] <= dep[j])
        {
            plfNeeded++;
            i++;
        }
        else
        {
            plfNeeded--;
            j++;
        }
        if (plfNeeded > maxPlf)
        {
            maxPlf = plfNeeded;
        }
    }

    return maxPlf;
}

int main()
{
    // can be completed
}