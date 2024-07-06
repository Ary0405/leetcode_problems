// Problem - Floor in BST (Coding Ninjas)
// Time Complexity - O(h)
// Space Complexity - O(1)

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class TreeNode
{
public:
    T val;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

int floorInBST(TreeNode<int> *root, int X)
{
    TreeNode<int> *temp = root;
    TreeNode<int> *ans = temp;
    while (temp != NULL)
    {
        if (temp->val > X)
        {
            temp = temp->left;
        }
        else
        {
            ans = temp;
            temp = temp->right;
        }
    }

    return ans->val;
}

int main()
{
    // can be completed
}