// Problem - 138 (Copy List with Random Pointer)
// Time Complexity = O(n)
// Space Complexity = O(n)

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

Node *copyRandomList(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }

    unordered_map<Node *, Node *> mp;

    Node *temp = head;

    while (temp != NULL)
    {
        mp.insert({temp, new Node(temp->val)});
        temp = temp->next;
    }

    temp = head;

    while (temp != NULL)
    {
        mp[temp]->next = mp[temp->next];
        mp[temp]->random = mp[temp->random];
        temp = temp->next;
    }

    return mp[head];
}

int main()
{
    // can be completed
}