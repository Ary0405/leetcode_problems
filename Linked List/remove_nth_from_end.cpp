// Problem - 19 (Remove Nth Node From End of List)
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

int lengthOfList(ListNode *head)
{
    int l = 0;
    ListNode *temp = head;
    while (temp != NULL)
    {
        l++;
        temp = temp->next;
    }
    return l;
}

ListNode *removeNthFromEnd(ListNode *head, int n)
{
    int len = lengthOfList(head);
    int remNode = len - n;

    if (remNode == 0)
    {
        ListNode *newHead = head->next;
        delete head;
        return newHead;
    }

    int c = 0;
    ListNode *temp = head;
    while (c != remNode - 1 && temp != NULL)
    {
        temp = temp->next;
        c++;
    }

    if (temp != NULL && temp->next != NULL)
    {
        ListNode *nodeToRemove = temp->next;
        temp->next = nodeToRemove->next;
        delete nodeToRemove;
    }

    return head;
}

int main()
{
    // can be completed
}