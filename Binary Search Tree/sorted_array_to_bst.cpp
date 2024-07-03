// Problem - 108 (Convert Sorted Array to Binary Search Tree)
// Time Complexity - O(n)
// Space Complexity - O(h)

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

TreeNode *solve(vector<int> &nums, int start, int end)
{
    if (start > end)
    {
        return NULL;
    }

    int mid = end + (start - end) / 2;

    TreeNode *node = new TreeNode(nums[mid]);
    node->left = solve(nums, start, mid - 1);
    node->right = solve(nums, mid + 1, end);

    return node;
}

TreeNode *sortedArrayToBST(vector<int> &nums)
{
    if (nums.size() == 0)
    {
        return NULL;
    }

    return solve(nums, 0, nums.size() - 1);
}

int main()
{
    // can be completed
}