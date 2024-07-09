// Problem - 703 (Kth Largest Element in a Stream)

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class KthLargest
{
    int kth;
    priority_queue<int, vector<int>, greater<int>> minHeap;

public:
    KthLargest(int k, std::vector<int> &nums)
    {
        kth = k;
        for (int num : nums)
        {
            add(num);
        }
    }

    int add(int val)
    {
        if (minHeap.size() < kth)
        {
            minHeap.push(val);
        }
        else if (val > minHeap.top())
        {
            minHeap.pop();
            minHeap.push(val);
        }
        return minHeap.top();
    }
};

int main()
{
    // can be completed
}