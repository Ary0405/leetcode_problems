// Problem - 295 (Find Median from Data Stream)

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class MedianFinder
{
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

public:
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        minHeap.push(num);
        maxHeap.push(minHeap.top());
        minHeap.pop();
        if (minHeap.size() < maxHeap.size())
        {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
    }

    double findMedian()
    {
        if (minHeap.size() == maxHeap.size())
        {
            return ((double)minHeap.top() + (double)maxHeap.top()) / 2;
        }
        return minHeap.top();
    }
};

int main()
{
    // can be completed
}