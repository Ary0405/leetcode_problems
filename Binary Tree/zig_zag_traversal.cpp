// Problem - 103 (Binary Tree Zigzag Level Order Traversal)
// Time Complexity - O(n)
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

vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    if (root == NULL)
    {
        return {};
    }

    vector<vector<int>> ans;
    queue<TreeNode *> q;

    q.push(root);

    bool lToR = false;

    while (!q.empty())
    {
        int n = q.size();
        vector<int> temp;

        for (int i = 1; i <= n; i++)
        {
            TreeNode *f = q.front();
            q.pop();
            temp.push_back(f->val);

            if (f->left)
            {
                q.push(f->left);
            }
            if (f->right)
            {
                q.push(f->right);
            }
        }
        ans.push_back(temp);
        lToR = !lToR;
    }

    for(int i = 1 ; i < ans.size() ; i+=2)
    {
        reverse(ans[i].begin(), ans[i].end());
    }

    return ans;
}