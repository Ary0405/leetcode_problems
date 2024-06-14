// Problem - 33 (Search in Rotated Sorted Array)
// Time Complexity = O(log(n))
// Space Complexity = O (1)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int search(vector<int> &nums, int target)
{
    if(nums.size() == 0)
    {
        return -1;
    }
    int pivot = 0;
    int hi = nums.size() - 1;
    int lo = 0;

    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }

        if (arr[mid] >= arr[lo])
        {
            if (target >= arr[lo] && target <= arr[mid])
            {
                hi = mid - 1;
            }
            else
            {
                lo = mid + 1;
            }
        }
        else
        {
            if (target >= arr[mid] && target < arr[hi])
            {
                lo = mid + 1;
            }
            else
            {
                hi = mid - 1;
            }
        }
    }

    return -1;
}

int main()
{
    // can be completed
}