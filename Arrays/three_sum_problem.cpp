// Problem - 15 (Three Sum)
// Time Complexity = O(n^2)
// Space Complexity = O (n)

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++)
    {
        if (i > 0 && nums[i - 1] == nums[i])
        {
            continue;
        }
        else
        {
            int k = i + 1;
            int l = nums.size() - 1;
            while (k < l)
            {
                int sum = nums[i] + nums[k] + nums[l];
                if (sum == 0)
                {
                    ans.push_back({nums[i], nums[k], nums[l]});
                    k++;
                    l--;
                    while (k < l && nums[k] == nums[k - 1])
                    {
                        k++;
                    }
                    while (k < l && nums[l] == nums[l + 1])
                    {
                        l++;
                    }
                }
                else if (sum < 0)
                {
                    k++;
                }
                else
                {
                    l--;
                }
            }
        }
    }

    return ans;
}

int main()
{
    // can be completed
}