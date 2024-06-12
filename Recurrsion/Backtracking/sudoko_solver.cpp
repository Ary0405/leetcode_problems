// Problem - 37 (Sudoko Solver)
// Time Complexity = O(9^n) - Here n is number of empthy cells
// Space Complexity = O(n)

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool isPossible(vector<vector<char>> &board, int num, int i, int j)
{
    // checking column
    for (int k = 0; k < 9; k++)
    {
        if (int(board[k][j] - '0') == num)
        {
            return false;
        }
    }

    // checking row
    for (int k = 0; k < 9; k++)
    {
        if (int(board[i][k] - '0') == num)
        {
            return false;
        }
    }

    // checking box
    for (int k = 0; k < 9; k++)
    {
        if (int(board[3 * (i / 3) + k / 3][3 * (j / 3) + k % 3] - '0') == num)
        {
            return false;
        }
    }

    return true;
}

bool solveSudokuHelper(vector<vector<char>> &board)
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] == '.')
            {
                for (int num = 1; num <= 9; num++)
                {
                    if (isPossible(board, num, i, j))
                    {
                        board[i][j] = '0' + num;
                        if (solveSudokuHelper(board))
                        {
                            return true;
                        }
                        board[i][j] = '.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void solveSudoku(vector<vector<char>> &board)
{
    solveSudokuHelper(board);
}

int main()
{
    // can be completed
}