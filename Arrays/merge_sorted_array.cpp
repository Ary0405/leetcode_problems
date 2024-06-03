// Problem - 88 (Merge Sorted Array)
// Time Complexity - O(n)
// Space Complexity - O(1)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int index = m;
    int i1 = 0;
    int i2 = 0;
    while (i1 < (m + n) && i2 < n)
    {
        if (i1 == index)
        {
            break;
        }
        if (nums1[i1] <= nums2[i2])
        {
            i1++;
        }
        else
        {
            nums1[index] = nums1[i1];
            nums1[i1] = nums2[i2];
            i2++;
            index++;
        }
    }

    while (i1 < (m + n) && i2 < n)
    {
        nums1[i1] = nums2[i2];
        i1++;
        i2++;
    }

    sort(nums1.begin(), nums1.end());
}

int main()
{
    // can be completed
}