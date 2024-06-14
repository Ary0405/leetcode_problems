// Problem - 4 (Median of Two Sorted Arrays)
// Time Complexity = O(n + m)
// Space Complexity = O (n + m)

#include <iostream>
#include <vector>
using namespace std;

void mergeSort(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3)
{
    int i = 0;
    int j = 0;
    while (i < nums1.size() && j < nums2.size())
    {
        if (nums1[i] < nums2[j])
        {
            nums3.push_back(nums1[i]);
            i++;
        }
        else
        {
            nums3.push_back(nums2[j]);
            j++;
        }
    }
    while (i < nums1.size())
    {
        nums3.push_back(nums1[i]);
        i++;
    }
    while (j < nums2.size())
    {
        nums3.push_back(nums2[j]);
        j++;
    }
}
double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> nums3;
    mergeSort(nums1, nums2, nums3);
    int n = nums3.size();
    if (n % 2 == 0)
    {
        return (nums3[n / 2] + nums3[n / 2 - 1]) / 2.0;
    }
    else
    {
        return nums3[n / 2];
    }
}

int main()
{
    // can be completed
}