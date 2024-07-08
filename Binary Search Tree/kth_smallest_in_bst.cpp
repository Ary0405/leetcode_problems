// Problem - 230 (Kth Smallest Element in a BST)
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

bool inorder(TreeNode *root, vector<int> &ans, int &temp, int k, int &ansT)
{
    if (root == NULL)
    {
        return false;
    }

    if (inorder(root->left, ans, temp, k, ansT))
    {
        return true;
    }

    ans.push_back(root->val);
    if (temp == k)
    {
        ansT = root->val;
        return true;
    }
    temp++;

    if (inorder(root->right, ans, temp, k, ansT))
    {
        return true;
    }

    return false;
}

int kthSmallest(TreeNode *root, int k)
{
    vector<int> in;
    int temp = 1;
    int ans = 0;
    inorder(root, in, temp, k, ans);

    return ans;
}

int main()
{
    // can be completed
}