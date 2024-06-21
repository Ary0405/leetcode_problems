// Problem - 8 (String to Integer)
// Time Complexity = O(n)
// Space Complexity = O (n)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int myAtoi(string s)
{
    string ans = "0";
    if (s.length() == 0)
    {
        return stoi(ans);
    }

    bool firstNum = false;

    int isNeg = false;
    if (s[0] == '-')
    {
        isNeg = true;
    }

    int i = 0;
    while (i < s.length())
    {
        // cout << s[i] << endl;
        if (s[i] == ' ')
        {
            if (ans == "0")
            {
                i++;
                continue;
            }
            else
            {
                break;
            }
        }
        else if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] == 'Z'))
        {
            break;
        }
        else if (s[i] == '-' || s[i] == '+' || s[i] == '.')
        {
            if (firstNum == true)
            {
                break;
            }
            if (ans == "0")
            {
                if (s[i] == '-')
                {
                    isNeg = true;
                }
                i++;
                continue;
            }
            else
            {
                break;
            }
        }
        else if (s[i] == '0')
        {
            firstNum = true;
            if (ans == "0")
            {
                i++;
                continue;
            }
            else
            {
                ans += s[i];
                i++;
            }
        }
        else
        {
            firstNum = true;
            ans += s[i];
            i++;
        }
    }

    if (isNeg)
    {
        return (-1 * stoi(ans));
    }

    return stoi(ans);
}

int main()
{
    // can be completed
    string temp = "    -0123";
    cout << myAtoi(temp) << endl;
}