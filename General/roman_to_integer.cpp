// Problem - 13 (Roman to Integer)
// Time Complexity = O(n)
// Space Complexity = O (1)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int romanToInt(string s)
{
    int ans = 0;
    int i = 0;

    while (i < s.length())
    {
        if (s[i] == 'I')
        {
            if (s[i + 1] == 'V')
            {
                ans += 4;
                i += 2;
            }
            else if (s[i + 1] == 'X')
            {
                ans += 9;
                i += 2;
            }
            else
            {
                ans += 1;
                i++;
            }
        }
        else if (s[i] == 'V')
        {
            ans += 5;
            i++;
        }
        else if (s[i] == 'X')
        {
            if (s[i + 1] == 'L')
            {
                ans += 40;
                i += 2;
            }
            else if (s[i + 1] == 'C')
            {
                ans += 90;
                i += 2;
            }
            else
            {
                ans += 10;
                i++;
            }
        }
        else if(s[i] == 'L')
        {
            ans += 50;
            i++;
        }
        else if(s[i] == 'C')
        {
            if (s[i + 1] == 'D')
            {
                ans += 400;
                i += 2;
            }
            else if (s[i + 1] == 'M')
            {
                ans += 900;
                i += 2;
            }
            else
            {
                ans += 100;
                i++;
            }
        }
        else if(s[i] == 'D')
        {
            ans += 500;
            i++;
        }
        else
        {
            ans += 1000;
            i++;
        }
    }

    return ans;
}

int main()
{
    // can be completed
}