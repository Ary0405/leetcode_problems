// Problem - 98 (Validate Binary Search Tree)
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

int findElement(vector<int> &inorder, int ele)
{
    for (int i = 0; i < inorder.size(); i++)
    {
        if (inorder[i] == ele)
        {
            return i;
        }
    }

    return -1;
}

TreeNode *helper(vector<int> &preorder, vector<int> &inorder, int &preIdx, int inordStart, int inordEnd)
{
    if (preIdx > preorder.size() || inordStart > inordEnd)
    {
        return NULL;
    }

    int element = preorder[preIdx++];
    TreeNode *root = new TreeNode(element);
    int position = findElement(inorder, element);
    root->left = helper(preorder, inorder, preIdx, inordStart, position - 1);
    root->right = helper(preorder, inorder, preIdx, position + 1, inordEnd);

    return root;
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    int preOrderIdx = 0;
    TreeNode *root = helper(preorder, inorder, preOrderIdx, 0, inorder.size() - 1);

    return root;
}

TreeNode *bstFromPreorder(vector<int> &preorder)
{
    vector<int> pre = preorder;
    sort(preorder.begin(), preorder.end());
    vector<int> inord = preorder;

    return buildTree(pre, inord);
}

int main()
{
    // can be completed
}