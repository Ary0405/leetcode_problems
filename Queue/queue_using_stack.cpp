// Problem - 232 (Implement Queue using Stacks)

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

class MyQueue
{
    stack<int> s1;
    stack<int> s2;

public:
    MyQueue()
    {
    }

    void push(int x)
    {
        s1.push(x);
    }

    int pop()
    {
        while (!s1.empty())
        {
            int topVal = s1.top();
            s2.push(topVal);
            s1.pop();
        }

        int top = s2.top();
        s2.pop();

        while (!s2.empty())
        {
            int topVal = s2.top();
            s1.push(topVal);
            s2.pop();
        }

        return top;
    }

    int peek()
    {
        while (!s1.empty())
        {
            int topVal = s1.top();
            s2.push(topVal);
            s1.pop();
        }

        int top = s2.top();

        while (!s2.empty())
        {
            int topVal = s2.top();
            s1.push(topVal);
            s2.pop();
        }

        return top;
    }

    bool empty()
    {
        return s1.empty();
    }
};

int main()
{
    // can be completed
}