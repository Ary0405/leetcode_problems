// Problem - Bottom View of a Binary Tree (Geeks for Geeks)
// Time Complexity - O(nlog(n))
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

vector<int> bottomView(Node *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }

    map<int, Node *> mp;

    queue<pair<Node *, int>> q;
    q.push({root, 0});

    mp[0] = root;

    while (!q.empty())
    {
        int n = q.size();
        for (int i = 1; i <= n; i++)
        {
            Node *f = q.front().first;
            int l = q.front().second;
            q.pop();
            mp[l] = f;

            if (f->left)
            {
                q.push({f->left, l - 1});
            }
            if (f->right)
            {
                q.push({f->right, l + 1});
            }
        }
    }

    map<int, Node*>::iterator it;
    for (it = mp.begin(); it != mp.end(); ++it) {
        ans.push_back(it->second->data);
    }
    return ans;
}

int main()
{
    // can be completed
}