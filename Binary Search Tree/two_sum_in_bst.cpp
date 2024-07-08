// Problem - 653 (Two Sum IV - Input is a BST)
// Time Complexity - O(n)
// Space Complexity - O(n)

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
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

bool helper(TreeNode *root, int k, map<int, bool> &mp)
{
    if (root == NULL)
    {
        return false;
    }

    if (helper(root->left, k, mp))
    {
        return true;
    }

    mp[root->val] = true;
    int sum = k - root->val;
    if (mp[sum] && sum != root->val)
    {
        return true;
    }

    if (helper(root->right, k, mp))
    {
        return true;
    }

    return false;
}

bool findTarget(TreeNode *root, int k)
{
    if (root == NULL)
    {
        return false;
    }

    map<int, bool> mp;

    return helper(root, k, mp);
}

int main()
{
    // can be completed
}