// Problem - 14 (Longest Common Prefix)
// Time Complexity = O(n)
// Space Complexity = O (n)

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

string longestCommonPrefix(vector<string> &strs)
{
    sort(strs.begin(), strs.end());
    string ans = "";
    int n = strs.size();
    string first = strs[0], last = strs[n - 1];
    for (int i = 0; i < min(first.length(), last.length()); i++)
    {
        if (first[i] == last[i])
        {
            ans += first[i];
        }
        else
        {
            return ans;
        }
    }
    return ans;
}

int main()
{
    // can be completed
}