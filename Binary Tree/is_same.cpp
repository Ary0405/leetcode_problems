// Problem - 100 (Same Tree)
// Time Complexity - O(n)
// Space Complexity - O(1)

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

bool isSameTree(TreeNode *p, TreeNode *q)
{
    if (p == NULL && q != NULL)
    {
        return false;
    }
    if (p != NULL && q == NULL)
    {
        return false;
    }
    if (p == NULL && q == NULL)
    {
        return true;
    }

    bool isLeftSame = isSameTree(p->left, q->left);
    bool isRightSame = isSameTree(p->right, q->right);

    if (isLeftSame && isRightSame)
    {
        if (p->val == q->val)
        {
            return true;
        }
    }

    return false;
}

int main()
{
    // can be completed
}