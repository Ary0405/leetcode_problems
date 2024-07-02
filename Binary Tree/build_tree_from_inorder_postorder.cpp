// Problem - 106 (Construct Binary Tree from postorder and Inorder Traversal)
// Time Complexity - O(n^2)
// Space Complexity - O(n)

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

int x;

TreeNode *solve(vector<int> &a, vector<int> &b, int s, int e)
{
    if (s > e)
        return NULL;
    TreeNode *node = new TreeNode(b[x++]);
    int i;
    for (i = s; i <= e; i++)
    {
        if (node->val == a[i])
        {
            break;
        }
    }
    node->right = solve(a, b, i + 1, e);
    node->left = solve(a, b, s, i - 1);
    return node;
}

TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
{
    reverse(postorder.begin(), postorder.end());
    x = 0;
    return solve(inorder, postorder, 0, inorder.size() - 1);
}

int main()
{
    // can be completed
}