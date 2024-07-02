// Problem - 101 (Symmetric Tree)
// Time Complexity - O(n)
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

bool helper(TreeNode *rL, TreeNode *rR)
{
    if ((rL == NULL && rR != NULL) || (rL != NULL && rR == NULL))
    {
        return false;
    }

    if (rR == NULL && rL == NULL)
    {
        return true;
    }

    bool h1 = helper(rL->left, rR->right);
    bool h2 = helper(rL->right, rR->left);

    if (h1 && h2)
    {
        if (rL->val == rR->val)
        {
            return true;
        }
    }

    return false;
}

bool isSymmetric(TreeNode *root)
{
    bool ans = helper(root->left, root->right);
    return ans;
}

int main()
{
    // can be completed
}