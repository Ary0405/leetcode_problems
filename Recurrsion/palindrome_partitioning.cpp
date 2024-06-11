// Problem - 131 (Palindrome Partitioning)
// Time Complexity = O(n (2^n))
// Space Complexity = O(n^2)

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool isPalindrome(string s, int st, int en)
{
    while (st <= en)
    {
        if (s[st++] != s[en--])
        {
            return false;
        }
    }
    return true;
}

void helper(string s, int ind, vector<vector<string>> &ans, vector<string> temp)
{
    if (ind == s.length())
    {
        ans.push_back(temp);
        return;
    }

    for (int i = ind; i < s.length(); i++)
    {
        if (isPalindrome(s, ind, i))
        {
            temp.push_back(s.substr(ind, i - ind + 1));
            helper(s, i + 1, ans, temp);
            temp.pop_back();
        }
    }
}

vector<vector<string>> partition(string s)
{
    vector<vector<string>> ans;
    helper(s, 0, ans, {});
    return ans;
}

int main()
{
    // can be completed
}