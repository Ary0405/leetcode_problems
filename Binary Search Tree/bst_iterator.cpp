// Problem - 173 (Binary Search Tree Iterator)

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

class BSTIterator
{
    TreeNode *tree;
    vector<int> ans;
    void inorder(TreeNode *root)
    {
        if (root == NULL)
        {
            return;
        }

        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }
    int k;

public:
    BSTIterator(TreeNode *root)
    {
        this->tree = root;
        inorder(this->tree);
        this->k = 0;
    }

    int next()
    {
        int val = this->ans[this->k];
        this->k++;
        return val;
    }

    bool hasNext()
    {
        if (this->k == this->ans.size() - 1)
        {
            return false;
        }
        return true;
    }
};

int main()
{
    // can be completed
}