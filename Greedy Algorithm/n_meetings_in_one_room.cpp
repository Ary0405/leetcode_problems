// Problem - N meetings in one room (Geeks for Geeks)
// Time Complexity = O(n log(n))
// Space Complexity = O (n)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxMeetings(int start[], int end[], int n)
{
    vector<vector<int>> v;
    for (int i = 0; i < n; i++)
    {
        v.push_back({start[i], end[i]});
    }

    sort(v.begin(), v.end(), [](const vector<int> &a, const vector<int> &b)
         { return a[1] < b[1]; });

    int ans = 1;
    int lim = v[0][1];

    for (int i = 1; i < n; i++)
    {
        if (v[i][0] > lim)
        {
            lim = v[i][1];
            ans++;
        }
    }

    return ans;
}

int main()
{
    int n = 6;
    int start[] = {1, 3, 0, 5, 8, 5};
    int end[] = {2, 4, 5, 7, 9, 9};
    int ans = maxMeetings(start, end, n);
    cout << ans << endl;
    return 0;
}