// Problem - Flattening of a Linked List (Geeks for Geeks)
// Time Complexity = O(n log(n))
// Space Complexity = O (n)

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    struct Node *bottom;

    Node(int x)
    {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

struct compare
{
    bool operator()(Node *a, Node *b)
    {
        return a->data > b->data;
    }
};

Node *flatten(Node *root)
{
    if (root == NULL)
    {
        return NULL;
    }

    priority_queue<Node *, vector<Node *>, compare> pq;

    Node *temp = root;
    while (temp != NULL)
    {
        Node *curr = temp;
        while (curr != NULL)
        {
            pq.push(curr);
            curr = curr->bottom;
        }
        temp = temp->next;
    }

    Node *newHead = new Node(0); 
    Node *current = newHead;

    while (!pq.empty())
    {
        Node *smallest = pq.top();
        pq.pop();
        current->next = smallest;
        smallest->bottom = NULL;
        current = current->next;
    }

    return newHead->next;
}

int main()
{
    // can be completed
}