// Problem - Kth largest element in BST (Geeks for Geeks)
// Time Complexity - O(n)
// Space Complexity - O(n)

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

void inorder(Node *root, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left, ans);
    ans.push_back(root->data);
    inorder(root->right, ans);
}

int kthLargest(Node *root, int K)
{
    vector<int> in;

    inorder(root, in);

    return in[in.size() - K];
}

int main()
{
    // can be completed
}