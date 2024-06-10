// Problem - Fractional Knapsack (Geeks for Geeks)
// Time Complexity = O(n log(n))
// Space Complexity = O (n)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item
{
    int value;
    int weight;
};

struct ItemD
{
    int value;
    int weight;
    double vpw;
};

double fractionalKnapsack(int w, Item arr[], int n)
{
    ItemD arrTemp[n];
    for (int i = 0; i < n; i++)
    {
        arrTemp[i].value = arr[i].value;
        arrTemp[i].weight = arr[i].weight;
        arrTemp[i].vpw = (double)arr[i].value / arr[i].weight;
    }
    sort(arrTemp, arrTemp + n, [](ItemD a, ItemD b)
         { return a.vpw > b.vpw; });
    
    double profit = 0;
    int weightTillNow = 0;

    for(int i = 0 ; i < n ; i++)
    {
        if(weightTillNow == w)
        {
            break;
        }
        int weightLeft = w - weightTillNow;
        if(weightLeft >= arrTemp[i].weight)
        {
            profit += arrTemp[i].value;
            weightTillNow += arrTemp[i].weight;
        }
        else
        {
            profit += arrTemp[i].vpw * weightLeft;
            weightTillNow += weightLeft;
        }
    }

    return profit;
}

int main()
{
    // can be completed
}