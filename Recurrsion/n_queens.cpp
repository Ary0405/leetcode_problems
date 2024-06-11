// Problem - 51 (N Queen Problem)
// Time Complexity = O(n!)
// Space Complexity = O(n^2)

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool isPossible(vector<string> &ans, int n, int i, int j)
{
    // checking if column
    for (int k = 0; k < n; k++)
    {
        if (ans[k][j] == 'Q')
        {
            return false;
        }
    }

    // checking if row
    for (int k = 0; k < n; k++)
    {
        if (ans[i][k] == 'Q')
        {
            return false;
        }
    }

    // checking upper left diagonal
    int k = i;
    int l = j;
    while (k >= 0 && l >= 0)
    {
        if (ans[k][l] == 'Q')
        {
            return false;
        }
        k--;
        l--;
    }

    // checking upper right diagonal
    int k = i;
    int l = j;
    while (k >= 0 && l < n)
    {
        if (ans[k][l] == 'Q')
        {
            return false;
        }
        k--;
        l++;
    }

    // checking lower right diagonal
    int k = i;
    int l = j;
    while (k < n && l < n)
    {
        if (ans[k][l] == 'Q')
        {
            return false;
        }
        k++;
        l++;
    }

    // checking lower left diagonal
    int k = i;
    int l = j;
    while (k < n && l >= 0)
    {
        if (ans[k][l] == 'Q')
        {
            return false;
        }
        k++;
        l--;
    }

    return true;
}

void solve(vector<string> &board, vector<vector<string>> &result, int n, int row)
{
    if (row == n)
    {
        result.push_back(board);
        return;
    }

    for (int col = 0; col < n; col++)
    {
        if (isPossible(board, n, row, col))
        {
            board[row][col] = 'Q';
            solve(board, result, n, row + 1);
            board[row][col] = '.';
        }
    }
}

vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> ans;
    vector<string> board(n);
    string s(n, '.');
    for (int i = 0; i < n; i++)
    {
        board[i] = s;
    }
    solve(board, ans, n, 0);
    return ans;
}

int main()
{
    // can be completed
}