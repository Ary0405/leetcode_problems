// Problem - Mirror Binary Tree (Geekd for Geeks)
// Time Complexity - O(n)
// Space Complexity - O(h)

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

void mirror(Node *node)
{
    if(node == NULL)
    {
        return;
    }

    mirror(node->left);
    mirror(node->right);

    Node* temp = root->left;
    root->left = root->right;
    root->right = temp;
}

int main()
{
    // can be completed
}