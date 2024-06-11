// Problem - 60 (Permutation Sequence)
// Time Complexity = O(n^2)
// Space Complexity = O(n)

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

string getPermutation(int n, int k)
{
    int fact = 1;
    vector<int> num;
    for (int i = 1; i < n; i++)
    {
        fact = fact * i;
        num.push_back(i);
    }
    num.push_back(n);
    string ans = "";
    k = k - 1;
    while (true)
    {
        ans = ans + to_string(num[k / fact]);
        num.erase(num.begin() + k / fact);
        if (num.size() == 0)
        {
            break;
        }
        k = k % fact;
        fact = fact / num.size();
    }
    return ans;
}

int main()
{
    // can be completed
}