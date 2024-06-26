// Problem - 543 (Diameter of Binary Tree)
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

int height(TreeNode *root, int &diameter)
{
    if (root == NULL)
    {
        return 0;
    }

    int lh = height(root->left, diameter);
    int rh = height(root->right, diameter);

    diameter = max(diameter, lh + rh);

    return 1 + max(lh, rh);
}

int diameterOfBinaryTree(TreeNode *root)
{
    int d = 0;

    int h = diameter(root, d);

    return d;
}

int main()
{
    // can be completed
}