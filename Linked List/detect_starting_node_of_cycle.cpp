// Problem - 142 (Linked List Cycle II)
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

bool hasCycle(ListNode *head)
{
    if (head == NULL)
    {
        return false;
    }
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            return true;
        }
    }

    return false;
}

ListNode *detectCycle(ListNode *head)
{
    if (head == NULL)
    {
        return NULL;
    }

    if (!hasCycle(head))
    {
        return NULL;
    }

    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            break;
        }
    }

    ListNode *temp = head;

    while (temp != slow)
    {
        temp = temp->next;
        slow = slow->next;
    }

    return slow;
}

int main()
{
    // can be completed
}