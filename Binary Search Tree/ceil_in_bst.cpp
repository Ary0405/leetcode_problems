// Problem - Ceil in BST (Coding Ninjas)
// Time Complexity - O(h)
// Space Complexity - O(1)

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~BinaryTreeNode()
    {
        if (left)
        {
            delete left;
        }
        if (right)
        {
            delete right;
        }
    }
};

void helper(BinaryTreeNode<int> *root, int x, int *ans)
{
    if (root == NULL)
    {
        return;
    }
    if (root->data == x)
    {
        *ans = root->data;
        return;
    }
    else if (root->data > x)
    {
        *ans = root->data;
        helper(root->left, x, ans);
    }
    else
    {
        helper(root->right, x, ans);
    }
}

int findCeil(BinaryTreeNode<int> *node, int x)
{
    // Write your code here.
    int ans = -1;
    helper(node, x, &ans);
    return ans;
}

int main()
{
    // can be completed
}