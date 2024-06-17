// Problem - Nearest Smaller Element (Interviewbit)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> prevSmaller(vector<int> &A)
{
    vector<int> ans;
    for(int i = 0 ; i < A.size() ; i++)
    {
        bool isPushed = false;
        for(int j = i - 1 ; j >= 0 ; j--)
        {
            if(A[j] < A[i])
            {
                ans.push_back(A[j]);
                isPushed = true;
                break;
            }
        }

        if(isPushed == false)
        {
            ans.push_back(-1);
        }
    }

    return ans;
}

int main()
{
    // can be completed
}