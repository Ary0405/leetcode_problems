// Problem - 234 (Palindrome Linked List)
// Time Complexity = O(n)
// Space Complexity = O (n)

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

bool isPalindrome(ListNode *head)
{
    if (head == NULL)
    {
        return false;
    }
    stack<int> st;
    ListNode *temp = head;
    while (temp != NULL)
    {
        st.push(temp->val);
        temp = temp->next;
    }
    temp = head;
    while (temp != NULL)
    {
        int top = st.top();
        st.pop();
        if (temp->val != top)
        {
            return false;
        }
        temp = temp->next;
    }
    return true;
}

int main()
{
    // can be completed
}