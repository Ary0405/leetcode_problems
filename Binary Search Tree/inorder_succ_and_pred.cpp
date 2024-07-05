// Problem - Predecessor and Successor (Geeks for Geeks)
// Time Complexity - O(h)
// Space Complexity - O(1)

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct Node
{
    int key;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        key = x;
        left = NULL;
        right = NULL;
    }
};

void findPreSuc(Node *root, Node *&pre, Node *&suc, int key)
{
    Node *curr = root;
    while (curr != NULL)
    {
        if (curr->key >= key)
        {
            curr = curr->left;
        }
        else
        {
            pre = curr;
            curr = curr->right;
        }
    }
    Node *curr2 = root;
    while (curr2 != NULL)
    {
        if (curr2->key > key)
        {
            suc = curr2;
            curr2 = curr2->left;
        }
        else
        {
            curr2 = curr2->right;
        }
    }
}

int main()
{
    // can be completed
}