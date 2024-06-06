// Problem - 3 (Longest Substring Without Repeating Characters)
// Time Complexity = O(n)
// Space Complexity = O (1)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int lengthOfLongestSubstring(string s)
{
    unordered_map<char, int> mp;
    int left = 0;
    int ans = 1;
    for (int i = 0; i < s.length(); i++)
    {
        mp[s[i]]++;
        while (mp[s[i]] > 1)
        {
            mp[s[left]]--;
            left++;
        }
        ans = max(ans, i - left + 1);
    }
    return ans;
}

int main()
{
    // can be completed
}