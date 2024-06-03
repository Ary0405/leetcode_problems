// Problem - 75 (Sort Colors)
// Time Complexity = O(n)
// Space Complexity = O (1)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void sortColors(vector<int> &nums)
{
    int lo = 0;
    int hi = nums.size() - 1;
    int mid = 0;
    while(mid <= hi)
    {
        if(nums[mid] == 0)
        {
            swap(nums[mid], nums[lo]);
            lo++;
            mid++;
        }
        else if(nums[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(nums[mid], nums[hi]);
            hi--;
        }
    }
}

int main()
{
    // can be completed
}