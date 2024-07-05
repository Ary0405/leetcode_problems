// Problem - 235 (Lowest Common Ancestor of a Binary Search Tree)
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

TreeNode *helper(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (root == NULL || root == p || root == q)
    {
        return root;
    }

    TreeNode *l = helper(root->left, p, q);
    TreeNode *r = helper(root->right, p, q);

    if (r == NULL)
    {
        return l;
    }

    if (l == NULL)
    {
        return r;
    }

    return root;
}

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (root == NULL || root == p || root == q || (p->val > root->val && q->val < root->val) || (p->val < root->val && q->val > root->val))
    {
        return root;
    }

    if (root->val > p->val && root->val > q->val)
    {
        return helper(root->left, p, q);
    }

    return helper(root->right, p, q);
}

int main()
{
    // can be completed
}