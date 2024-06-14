// Problem - Allocate Minimum Number of Pages (Interviewbit)
// Time Complexity = O(n)
// Space Complexity = O (1)

#include <iostream>
#include <vector>
using namespace std;

int countStudents(vector<int> &pages, int pages)
{
    int stu = 1;
    long long pageAlloc = 0;
    for(int i = 0 ; i < pages.size() ; i++)
    {
        if(pageAlloc + pages[i] <= pages)
        {
            pageAlloc += pages[i];
        }
        else
        {
            pageAlloc = pages[i];
            stu++;
        }
    }

    return stu;
}

int findPages(vector<int> &pages, int m, int n)
{
    if(m > n)
    {
        return -1;
    }
    int sum = 0;
    int maxEle = pages[0];

    for(int i = 0 ; i < n ; i++)
    {
        sum += pages[i];
        maxEle = max(maxEle, pages[i]);
    }

    int hi = sum;
    int lo = maxEle;

    while(lo <= hi)
    {
        int mid = lo + (hi-lo)/2;
        int students = countStudents(pages,mid);
        if(students > m)
        {
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }

    return lo;
}

int main()
{
    // can be completed
}