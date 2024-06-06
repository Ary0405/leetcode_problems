// Problem - 18 (Four Sum)
// Time Complexity = O(n^2)
// Space Complexity = O (n)

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
        {
            continue;
        }
        else
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (j > i + 1 && nums[j] == nums[j - 1])
                {
                    continue;
                }
                else
                {
                    int k = j + 1;
                    int l = nums.size() - 1;
                    while (k < l)
                    {
                        if (nums[i] + nums[j] + nums[k] + nums[l] == target)
                        {
                            ans.push_back({nums[i], nums[j], nums[k], nums[l]});
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
                        else if (nums[i] + nums[j] + nums[k] + nums[l] < target)
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
        }
    }
    return ans;
}

int main()
{
    // can be completed
}