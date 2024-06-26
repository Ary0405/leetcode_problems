// Problem - 104 (Maximum Depth of Binary Tree)
// Time Complexity - O(n)
// Space Complexity - O(h)

#include <iostream>
#include <vector>
#include <algorithm>
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

int maxDepth(TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int lh = maxDepth(root->left);
    int rh = maxDepth(root->right);

    int maxH = max(lh, rh) + 1;

    return maxH;
}

int main()
{
    // can be completed
}