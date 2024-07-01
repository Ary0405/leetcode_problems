// Problem - 124 (Maximum Path Sum)
// Time Complexity - O(h)
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

int helper(TreeNode *root, int &res)
{
    if (root == NULL)
    {
        return 0;
    }

    int leftSum = helper(root->left, res);
    int rightSum = helper(root->right, res);

    int temp = max(max(leftSum, rightSum) + root->val, root->val);
    res = max(max(temp, root->val + leftSum + rightSum), res);

    return temp;
}

int maxPathSum(TreeNode *root)
{
    int res = INT_MIN;
    helper(root, res);
    return res;
}

int main()
{
    // can be completed
}