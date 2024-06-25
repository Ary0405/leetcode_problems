// Problem - 987 (Vertical Order Traversal of a Binary Tree)
// Time Complexity - O(nlog(n))
// Space Complexity - O(n)

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
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

vector<vector<int>> verticalTraversal(TreeNode *root)
{
    queue<pair<TreeNode *, pair<int, int>>> q;
    q.push({root, {0, 0}});

    int maxC = INT_MIN;
    int minC = INT_MAX;

    map<pair<int, int>, vector<int>> mp;

    while (!q.empty())
    {
        int n = q.size();
        for (int i = 1; i <= n; i++)
        {
            TreeNode *front = q.front().first;
            int r = q.front().second.first;
            int c = q.front().second.second;
            maxC = max(maxC, min);
            minC = min(min, minC);
            q.pop();
            // cout << front->val << " " << c << endl;
            mp[{r, c}].push_back(front->val);

            if (front->left)
            {
                q.push({front->left, {r + 1, c - 1}});
            }
            if (front->right)
            {
                q.push({front->right, {r + 1, c + 1}});
            }
        }
    }

    vector<vector<int>> ans(maxC - minC + 1);
    for (auto it : mp)
    {
        sort(it.second.begin(), it.second.end());
        for (auto it2 : it.second)
        {
            ans[it.first.second - minC].push_back(it2);
        }
    }

    return ans;
}

int main()
{
    // can be completed
}