// Problem - 25 (Reverse Nodes in k-Group)
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

ListNode *reverseKNodes(ListNode *head, int k)
{
    ListNode *prev = NULL;
    ListNode *temp = head;
    ListNode *next = NULL;
    int count = 0;
    while (temp != NULL && count < k)
    {
        next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
        count++;
    }

    return prev;
}

ListNode *reverseKGroup(ListNode *head, int k)
{
    if (head == NULL || k <= 1)
    {
        return head;
    }

    ListNode *dummy = new ListNode(-1);
    dummy->next = head;
    ListNode *prev = dummy;
    ListNode *curr = head;

    while (curr != NULL)
    {
        ListNode *start = prev->next;
        ListNode *end = curr;
        int count = 0;

        while (end != NULL && count < k)
        {
            end = end->next;
            count++;
        }

        if (count == k)
        {
            ListNode *nextSegmentStart = end;                         
            ListNode *reversedSegmentStart = reverseKNodes(start, k);

            prev->next = reversedSegmentStart;
            start->next = nextSegmentStart;

            prev = start;
            curr = nextSegmentStart;
        }
        else
        {
            break;
        }
    }

    return dummy->next;
}

int main()
{
    // can be completed
}