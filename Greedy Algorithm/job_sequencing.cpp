// Problem - Job Sequencing Problem (Geeks for Geeks)
// Time Complexity = O(n log(n) + nd)
// Space Complexity = O (d)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Job
{
    int id;
    int dead;
    int profit;
};

bool comparison(Job a, Job b)
{
    if (a.dead == b.dead)
    {
        return a.profit > b.profit;
    }
    return a.dead < b.dead;
}

vector<int> JobScheduling(Job arr[], int n)
{
    sort(arr, arr + n, comparison);
    int maxDead = -1;
    for (int i = 0; i < n; i++)
    {
        maxDead = max(maxDead, arr[i].dead);
    }
    int slots[maxDead + 1];
    for (int i = 0; i < maxDead + 1; i++)
    {
        slots[i] = -1;
    }

    int maxProfit = 0;
    int noOfJobs = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = arr[i].dead; j > 0; j--)
        {
            if (slots[j] == -1)
            {
                slots[j] = i;
                maxProfit += arr[i].profit;
                noOfJobs++;
                break;
            }
        }
    }
    vector<int> ans = {noOfJobs, maxProfit};
    return ans;
}
int main()
{
    // can be completed
}