// Problem - 225 (Implement Stack using Queues)

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class MyStack
{
    queue<int> q1;
    queue<int> q2;

public:
    MyStack() {}

    void push(int x)
    {
        q1.push(x);
    }

    int pop()
    {
        if (q1.empty() && q2.empty())
        {
            return -1;
        }

        if (q1.empty())
        {
            while (q2.size() > 1)
            {
                q1.push(q2.front());
                q2.pop();
            }
            int val = q2.front();
            q2.pop();
            return val;
        }
        else
        {
            while (q1.size() > 1)
            {
                q2.push(q1.front());
                q1.pop();
            }
            int val = q1.front();
            q1.pop();
            return val;
        }
    }

    int top()
    {
        if (q1.empty() && q2.empty())
        {
            return -1;
        }

        if (q1.empty())
        {
            while (q2.size() > 1)
            {
                q1.push(q2.front());
                q2.pop();
            }
            int val = q2.front();
            q1.push(q2.front());
            q2.pop();
            return val;
        }
        else
        {
            while (q1.size() > 1)
            {
                q2.push(q1.front());
                q1.pop();
            }
            int val = q1.front();
            q2.push(q1.front());
            q1.pop();
            return val;
        }
    }

    bool empty()
    {
        return q1.empty() && q2.empty();
    }
};

int main()
{
    // can be completed
}