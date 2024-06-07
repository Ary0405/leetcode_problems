// Problem - 237 (Delete Node in a Linked List)
// Time Complexity = O(1)
// Space Complexity = O(1)

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

void deleteNode(ListNode *node)
{
    if (node == NULL)
    {
        return;
    }

    if (node->next == NULL)
    {
        node = NULL;
        return;
    }

    if (node->next->next == NULL)
    {
        node->val = node->next->val;
        node->next = NULL;
        return;
    }

    node->val = node->next->val;
    node->next = node->next->next;
    return;
}

int main()
{
    // can be completed
}