// Problem - 155 (Min Stack)

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

class MinStack
{
    stack<int> st;
    stack<int> st2;
    stack<int> temp;

public:
    MinStack()
    {
    }

    void push(int val)
    {
        st.push(val);

        while (!st2.empty() && st2.top() <= val)
        {
            int top = st2.top();
            st2.pop();
            temp.push(top);
        }

        st2.push(val);

        while (!temp.empty())
        {
            st2.push(temp.top());
            temp.pop();
        }
    }

    void pop()
    {
        int top = st.top();
        st.pop();

        while (!st2.empty() && st2.top() != top)
        {
            temp.push(st2.top());
            st2.pop();
        }

        st2.pop();

        while (!temp.empty())
        {
            st2.push(temp.top());
            temp.pop();
        }
    }

    int top()
    {
        if (st.empty())
        {
            return -1;
        }

        return st.top();
    }

    int getMin()
    {
        if(st.empty())
        {
            return -1;
        }

        return st2.top();
    }
};

int main()
{
    // can be completed
}