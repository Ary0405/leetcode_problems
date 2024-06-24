// Problem - Left View of a Binary Tree (Geeks for Geeks)
// Time Complexity - O(n)
// Space Complexity - O(n)

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
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

vector<int> leftView(Node *root)
{
    vector<int> ans;

    if (root == NULL)
    {
        return ans;
    }

    queue<Node *> q;
    q.push(root);
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();
        for (int i = 1; i <= n; i++)
        {
            Node *front = q.front();
            q.pop();
            if (i == 1)
            {
                ans.push_back(front->data);
            }
            if (front->left)
            {
                q.push(front->left);
            }
            if (front->right)
            {
                q.push(front->right);
            }
        }
    }

    return ans;
}