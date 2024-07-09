// Problem - 297 (Serialize and Deserialize Binary Tree)

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
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

// Encodes a tree to a single string.
string serialize(TreeNode *root)
{
    if (root == NULL)
    {
        return "NULL,";
    }

    return to_string(root->val) + "," + serialize(root->left) + serialize(root->right);
}

TreeNode *helper(queue<string> &q)
{
    string s = q.front();
    q.pop();
    if (s == "NULL")
    {
        return NULL;
    }

    TreeNode *root = new TreeNode(stoi(s));
    root->left = helper(q);
    root->right = helper(q);

    return root;
}

// Decodes your encoded data to tree.
TreeNode *deserialize(string data)
{
    queue<string> q;
    string s;

    for (int i = 0; i < data.size(); i++)
    {
        if (data[i] == ',')
        {
            q.push(s);
            s = "";
            continue;
        }
        s += data[i];
    }

    if (s.size() != 0)
    {
        q.push(s);
    }

    return helper(q);
}

int main()
{
    // can be completed
}