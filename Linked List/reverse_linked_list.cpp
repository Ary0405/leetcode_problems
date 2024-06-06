// Problem - 206 (Reverse Linked List)
// Time Complexity = O(n)
// Space Complexity = O (1)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *reverseList(ListNode *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    ListNode *temp = head;
    ListNode *prev = NULL;
    ListNode *next = NULL;

    while (temp != NULL)
    {
        next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }

    return prev;
}

int main()
{
    // can be completed
}