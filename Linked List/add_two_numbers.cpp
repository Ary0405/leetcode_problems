// Problem - 2 (Add Two Numbers)
// Time Complexity = O(max(m,n))
// Space Complexity = O(max(m,n))

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

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *head = NULL;
    ListNode *temp = NULL;
    int carry = 0;
    int sum = 0;

    while (l1 != NULL && l2 != NULL)
    {
        sum = carry;
        if (l1 != NULL)
        {
            sum += l1->val;
            l1 = l1->next;
        }

        if (l2 != NULL)
        {
            sum += l2->val;
            l2 = l2->next;
        }

        ListNode *node = new ListNode(sum % 10);

        carry = sum / 10;

        if (temp == NULL)
        {
            temp = head = node;
        }
        else
        {
            temp->next = node;
            temp = temp->next;
        }
    }

    if (carry > 0)
    {
        temp->next = new ListNode(carry);
    }

    return head;
}

int main()
{
    // can be completed
}