// Problem - K-th element of two Arrays (Geeks for Geeks)
// Time Complexity = O(k)
// Space Complexity = O (1)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int kthElement(int arr1[], int arr2[], int n, int m, int k)
{
    int t1 = 0;
    int t2 = 0;
    int count = 0;
    int kthElement = -1;

    while (t1 < n && t2 < m)
    {
        if (arr1[t1] < arr2[t2])
        {
            kthElement = arr1[t1];
            t1++;
        }
        else
        {
            kthElement = arr2[t2];
            t2++;
        }
        count++;
        if (count == k)
        {
            return kthElement;
        }
    }

    while (t1 < n)
    {
        kthElement = arr1[t1];
        t1++;
        count++;
        if (count == k)
        {
            return kthElement;
        }
    }

    while (t2 < m)
    {
        kthElement = arr2[t2];
        t2++;
        count++;
        if (count == k)
        {
            return kthElement;
        }
    }

    return -1;
}

int main()
{
    // can be completed
}