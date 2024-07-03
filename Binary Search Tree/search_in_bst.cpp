// Problem - 700 (Search in a Binary Search Tree)
// Time Complexity - O(h)
// Space Complexity - O(h)

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *searchBST(TreeNode *root, int val)
{
    if (root == NULL || val == root->val)
    {
        return root;
    }

    if (val > root->val)
    {
        return searchBST(root->right, val);
    }
    else
    {
        return searchBST(root->left, val);
    }

    return NULL;
}

int main()
{
    // can be completed
}