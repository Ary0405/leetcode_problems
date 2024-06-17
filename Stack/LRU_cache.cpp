// Problem - 225 (LRU Cache)
// Time Complexity - O(n)
// Space Complexity - O(n)

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

class LRUCache
{
    stack<pair<int, int>> mainStack;
    stack<pair<int, int>> tempStack;
    unordered_map<int, int> cache;
    int capacity;
    int currentSize;

public:
    LRUCache(int capacity)
    {
        this->capacity = capacity;
        this->currentSize = 0;
    }

    int get(int key)
    {
        if (cache.find(key) == cache.end())
        {
            return -1; 
        }

        int value;
        while (!mainStack.empty())
        {
            pair<int, int> top = mainStack.top();
            mainStack.pop();
            if (top.first == key)
            {
                value = top.second;
                while (!tempStack.empty())
                {
                    mainStack.push(tempStack.top());
                    tempStack.pop();
                }
                break;
            }
            else
            {
                tempStack.push(top);
            }
        }

        while (!tempStack.empty())
        {
            mainStack.push(tempStack.top());
            tempStack.pop();
        }

        mainStack.push(make_pair(key, value));

        return value;
    }

    void put(int key, int value)
    {
        bool found = false;
        while (!mainStack.empty())
        {
            pair<int, int> top = mainStack.top();
            mainStack.pop();
            if (top.first == key)
            {
                found = true;

                break;
            }
            else
            {
                tempStack.push(top);
            }
        }

        // If the key was not found and the cache is at capacity, remove the least recently used item
        if (!found && currentSize == capacity)
        {
            cache.erase(mainStack.top().first);
            mainStack.pop();
            currentSize--;
        }

        // Move the rest of the items back to the main stack
        while (!tempStack.empty())
        {
            mainStack.push(tempStack.top());
            tempStack.pop();
        }

        // Add the new key-value pair to the stack
        mainStack.push(make_pair(key, value));
        cache[key] = value;

        if (!found)
        {
            currentSize++;
        }
    }
};