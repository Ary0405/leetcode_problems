// Problem - Sort A Stack (Coding Ninjas)

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

void Sorted(stack<int> &stack, int num)
{

    if (stack.empty())
    {
        stack.push(num);
        return;
    }

    if (stack.top() < num)
    {
        stack.push(num);
        return;
    }

    int l = stack.top();

    stack.pop();

    Sorted(stack, num);

    stack.push(l);
}

void sortStack(stack<int> &stack)

{

    if (stack.empty())
    {
        return;
    }

    int num = stack.top();

    stack.pop();

    sortStack(stack);

    Sorted(stack, num);
}

int main()
{
    // can be completed
}