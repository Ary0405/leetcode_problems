// Problem - 116 (Populating Next Right Pointers in Each Node)
// Time Complexity - O(n)
// Space Complexity - O(n)

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

Node *connect(Node *root)
{
    if (root == NULL)
    {
        return NULL;
    }

    vector<vector<Node *>> ans;
    queue<Node *> q;

    q.push(root);

    while (!q.empty())
    {
        int n = q.size();
        vector<Node* > temp;
        for (int i = 1; i <= n; i++)
        {
            Node *f = q.front();
            q.pop();
            temp.push_back(f);
            if (f->left)
            {
                q.push(f->left);
            }
            if (f->right)
            {
                q.push(f->right);
            }
        }
        temp.push_back(NULL);
        ans.push_back(temp);
    }

    for(int i = 0 ; i < ans.size() ; i++)
    {
        for(int j = 0 ;j < ans[i].size() ; j++)
        {
            if (j != ans[i].size() - 1)
            {
                ans[i][j]->next = ans[i][j+1];
            }
        }
    }

    return root;
}

int main()
{
    // can be completed
}