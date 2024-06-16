// Problem - 496 (Next Greater Element I)
// Time Complexity = O(n*m)
// Space Complexity = O (n)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> ans;

    for (int i = 0; i < nums1.size(); i++)
    {
        bool isPushed = false;
        int j = 0;
        while (nums2[j] != nums1[i])
        {
            j++;
        }
        for (int k = j; k < nums2.size(); k++)
        {
            if (nums2[k] > nums1[i])
            {
                isPushed = true;
                ans.push_back(nums2[k]);
                break;
            }
        }

        if (isPushed == false)
        {
            ans.push_back(-1);
        }
    }

    return ans;
}

int main()
{
    // can be completed
}