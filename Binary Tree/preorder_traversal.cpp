// Problem - 144 (Binary Tree Preorder Traversal)
// Time Complexity - O(n)
// Space Complexity - O(n)

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

void preorder(TreeNode *root, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }

    ans.push_back(root->val);
    preorder(root->left, ans);
    preorder(root->right, ans);
}

vector<int> preorderTraversal(TreeNode *root)
{
    vector<int> ans;
    preorder(root, ans);
    return ans;
}

int main()
{
    // can be completed
}
