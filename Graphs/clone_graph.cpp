// Problem - 133 (Clone Graph)
// Time Complexity - O(V+E)
// Space Complexity - O(V)

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

class Node
{
public:
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

Node *cloneGraph(Node *node)
{
    if(node == NULL)
    {
        return NULL;
    }

    unordered_map<Node*, Node*> mp;

    unordered_map<Node* , bool> visited;

    visited[node] = true;

    queue<Node*> q;

    q.push(node);

    while(!q.empty())
    {
        Node* temp = q.front();
        q.pop();

        Node* newNode = new Node(temp->val);
        mp[temp] = newNode;

        for(Node* n : temp->neighbors)
        {
            if(visited.find(n) == visited.end())
            {
                visited[n] = true;
                q.push(n);
            }
        }
    }

    for(auto it : mp)
    {
        Node* temp = it.first;
        Node* newNode = it.second;

        for(Node* n : temp->neighbors)
        {
            newNode->neighbors.push_back(mp[n]);
        }
    }

    return mp[node];
}

int main()
{
    // can be completed
}