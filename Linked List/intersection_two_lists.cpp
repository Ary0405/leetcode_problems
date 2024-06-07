// Problem - 160 (Intersection of Two Linked Lists)
// Time Complexity = O(m+n)
// Space Complexity = O (m)

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    unordered_map<ListNode *, bool> mp;
    ListNode *t1 = headA;
    ListNode *t2 = headB;

    while (t1 != NULL)
    {
        mp[t1] = true;
        t1 = t1->next;
    }

    while (t2 != NULL)
    {
        if (mp.find(t2) != mp.end())
        {
            return t2;
        }
        t2 = t2->next;
    }

    return NULL;
}

int main()
{
    // can be completed
}