// Problem - Boundary Traversal (LeetCode - Premium)
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

bool isLeaf(TreeNode *root)
{
    return !root->left && !root->right;
}

void leftView(TreeNode *root, vector<int> &ans)
{
    queue<TreeNode *> q;

    q.push(root);

    while (!q.empty())
    {
        int n = q.size();
        for (int i = 1; i <= n; i++)
        {
            TreeNode *f = q.front();
            q.pop();
            if (i == 1)
            {
                if (isLeaf(f))
                {
                    continue;
                }
                else
                {
                    ans.push_back(f->val);
                }
            }
            if (f->left)
            {
                q.push(f->left);
            }
            if (f->right)
            {
                q.push(f->right);
            }
        }
    }

    return;
}

void addLeaves(TreeNode *root, vector<int> &ans)
{
    if (isLeaf(root))
    {
        ans.push_back(root->val);
        return;
    }

    if (root->left)
    {
        addLeaves(root->left, ans);
    }
    if (root->right)
    {
        addLeaves(root->right, ans);
    }

    return;
}

void rightView(TreeNode *root, vector<int> &ans)
{
    queue<TreeNode *> q;

    q.push(root);

    vector<int> temp;

    while (!q.empty())
    {
        int n = q.size();
        for (int i = 1; i <= n; i++)
        {
            TreeNode *f = q.front();
            q.pop();
            if (i == n)
            {
                if (isLeaf(f))
                {
                    continue;
                }
                else
                {
                    temp.push_back(f->val);
                }
            }
            if (f->left)
            {
                q.push(f->left);
            }
            if (f->right)
            {
                q.push(f->right);
            }
        }
    }

    for (int i = temp.size() - 1; i >= 1; i--)
    {
        ans.push_back(temp[i]);
    }

    return;
}

vector<int> boundaryTraversal(TreeNode *root)
{
    vector<int> ans;

    if (root == NULL)
    {
        return ans;
    }

    leftView(root, ans);
    addLeaves(root, ans);
    rightView(root, ans);

    return ans;
}

void printResult(const vector<int> &result)
{
    for (int val : result)
    {
        cout << val << " ";
    }
    cout << endl;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    vector<int> result = boundaryTraversal(root);

    cout << "Boundary Traversal: ";
    printResult(result);

    return 0;
}