// Problem - 151 (Reverse Words in a String)
// Time Complexity = O(n)
// Space Complexity = O (n)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string reverseWords(string s)
{
    vector<string> words;
    int i = 0;
    while (i < s.length())
    {
        if (s[i] == ' ')
        {
            i++;
            continue;
        }
        else
        {
            string temp;
            while (i < s.length() && s[i] != ' ')
            {
                temp += s[i];
                i++;
            }
            words.push_back(temp);
        }
    }
    string ans;
    for (int j = words.size() - 1; j >= 0; j--)
    {
        ans += words[j];
        if (j != 0)
        {
            ans += " ";
        }
    }
    return ans;
}

int main()
{
    // can be completed
    string s = "hi i am good";
    cout << reverseWords(s) << endl;
    return 0;
}