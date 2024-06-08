// Problem - 61 (Rotate List)
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

ListNode *rotateRight(ListNode *head, int k)
{
    if (head == NULL)
    {
        return NULL;
    }

    int len = lengthOfList(head);
    int actualK = k % len;
    if (actualK == 0)
    {
        return head;
    }
    int remNode = len - actualK;

    ListNode *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = head;

    int c = 0;
    ListNode *temp2 = head;
    while (c != remNode - 1 && temp2 != NULL)
    {
        temp2 = temp2->next;
        c++;
    }

    ListNode *newHead = temp2->next;
    temp2->next = NULL;

    return newHead;
}

int main()
{
    // can be completed
}