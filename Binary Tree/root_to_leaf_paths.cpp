// Problem - Root to Leaf Paths (Geeks for Geeks)
// Time Complexity - O(n)
// Space Complexity - O(n)

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

void helper(Node *root, vector<vector<int>> &ans, vector<int> temp)
{
    if (root->left == NULL && root->right == NULL)
    {
        temp.push_back(root->data);
        ans.push_back(temp);
        return;
    }

    temp.push_back(root->data);
    if (root->left)
    {
        helper(root->left, ans, temp);
    }

    if (root->right)
    {
        helper(root->right, ans, temp);
    }
}

vector<vector<int>> Paths(Node *root)
{
    // code here
    if (root == NULL)
    {
        return {};
    }

    vector<vector<int>> ans;
    helper(root, ans, {});
    return ans;
}