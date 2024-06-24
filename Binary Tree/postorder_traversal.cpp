// Problem - 145 (Binary Tree Postorder Traversal)
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

void postorder(TreeNode *root, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }

    ans.push_back(root->val);
    postorder(root->left, ans);
    postorder(root->right, ans);
}

vector<int> postorderTraversal(TreeNode *root)
{
    vector<int> ans;
    postorder(root, ans);
    return ans;
}

int main()
{
    // can be completed
}
