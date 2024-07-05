// Problem - 1008 (Construct Binary Search Tree from Preorder Traversal)
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

bool helper(TreeNode *root, long long int max_value, long long int min_value)
{
    if (root == NULL)
    {
        return true;
    }
    if (root->val < max_value && root->val > min_value)
    {
        if (helper(root->left, root->val, min_value) && helper(root->right, max_value, root->val))
        {
            return true;
        }
    }
    return false;
}

bool isValidBST(TreeNode *root)
{
    long long int max_value = 2147483648;
    cout << max_value << endl;
    long long int min_value = -2147483649;
    return helper(root, max_value, min_value);
}

int main()
{
    // can be completed
}