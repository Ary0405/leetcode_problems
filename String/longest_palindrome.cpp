// Problem - 5 (Longest Palindromic Substring)
// Time Complexity = O(n^2)
// Space Complexity = O (n)

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

string palFind(string s, int left, int right)
{
    while (left >= 0 && right < s.length() && s[left] == s[right])
    {
        left--;
        right++;
    }
    return s.substr(left + 1, right - left - 1);
}

string longestPalindrome(std::string s)
{
    if (s.length() <= 1)
    {
        return s;
    }

    string max_str = s.substr(0, 1);

    for (int i = 0; i < s.length() - 1; i++)
    {
        string odd = palFind(s,i, i);
        string even = palFind(s,i, i + 1);

        if (odd.length() > max_str.length())
        {
            max_str = odd;
        }
        if (even.length() > max_str.length())
        {
            max_str = even;
        }
    }

    return max_str;
}

int main()
{
    // can be completed
}