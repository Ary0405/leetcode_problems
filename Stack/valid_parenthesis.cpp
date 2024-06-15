// Problem - 20 (Valid Parenthesis)
// Time Complexity - O(n)
// Space Complexity - O(n)

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

bool isValid(string s)
{
    if (s.length() == 0)
    {
        return true;
    }

    stack<char> st;

    bool isV = true;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '[' || s[i] == '{' || s[i] == '(')
        {
            st.push(s[i]);
        }
        else
        {
            if (s[i] == ')')
            {
                char topVal = st.top();
                if (topVal == '(')
                {
                    st.pop();
                    continue;
                }
                else
                {
                    isV = false;
                    break;
                }
            }
            else if (s[i] == '}')
            {
                char topVal = st.top();
                if (topVal == '{')
                {
                    st.pop();
                    continue;
                }
                else
                {
                    isV = false;
                    break;
                }
            }
            else if (s[i] == ']')
            {
                char topVal = st.top();
                if (topVal == '[')
                {
                    st.pop();
                    continue;
                }
                else
                {
                    isV = false;
                    break;
                }
            }
        }
    }

    if(st.empty() == false)
    {
        isV = false;
    }

    return isV;
}

int main()
{
    // can be completed
}