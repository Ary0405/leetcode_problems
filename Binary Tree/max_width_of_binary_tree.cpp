// Problem - 662 (Maximum Width of Binary Tree)
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

int widthOfBinaryTree(TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }

    queue<pair<TreeNode *, int>> q;
    q.push({root, 0});

    int ans = INT_MIN;

    while (!q.empty())
    {
        int n = q.size();
        int first, last;
        for (int i = 1; i <= n; i++)
        {
            TreeNode *f = q.front().first;
            int c = q.front().second;
            q.pop();
            if (i == 1)
            {
                first = c;
            }

            if (i == n)
            {
                last = c;
            }

            if (f->left)
            {
                q.push({f->left, 2 * c + 1});
            }

            if (f->right)
            {
                q.push({f->right, 2 * c + 2});
            }
        }

        ans = max(ans, last - first + 1);
    }

    return ans;
}