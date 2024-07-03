// Problem - Children Sum in a Binary Tree (Geeks for Geeks)
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

bool isLeafNode(Node *node)
{
    if (node == NULL)
    {
        return false;
    }
    return (node->left == NULL && node->right == NULL);
}

bool helper(Node *root)
{
    if (root == NULL)
    {
        return true;
    }

    if (isLeafNode(root))
    {
        return true;
    }

    bool leftSubtree = helper(root->left);
    bool RightSubtree = helper(root->right);

    if (leftSubtree && RightSubtree)
    {
        int sum = 0;
        if (root->left)
        {
            sum += root->left->data;
        }

        if (root->right)
        {
            sum += root->right->data;
        }

        if (sum == root->data)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    return false;
}

int isSumProperty(Node *root)
{
    if (root == NULL)
    {
        return 1;
    }
    if (helper(root))
    {
        return 1;
    }
    return 0;
}

int main()
{
    // can be completed
}