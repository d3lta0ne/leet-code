#define SIZE 3

#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    string winner(char grid[SIZE][SIZE])
    {
        char playerA = 'X';
        char playerB = 'O';

        // Check rows
        for (int i = 0; i < SIZE; i++)
        {
            if (grid[i][0] == playerA && grid[i][1] == playerA && grid[i][2] == playerA)
            {
                return "A";
            }
            if (grid[i][0] == playerB && grid[i][1] == playerB && grid[i][2] == playerB)
            {
                return "B";
            }
        }

        // Check columns
        for (int i = 0; i < SIZE; i++)
        {
            if (grid[0][i] == playerA && grid[1][i] == playerA && grid[2][i] == playerA)
            {
                return "A";
            }
            if (grid[0][i] == playerB && grid[1][i] == playerB && grid[2][i] == playerB)
            {
                return "B";
            }
        }

        // Check diagonals
        if (grid[0][0] == playerA && grid[1][1] == playerA && grid[2][2] == playerA)
        {
            return "A";
        }
        if (grid[0][0] == playerB && grid[1][1] == playerB && grid[2][2] == playerB)
        {
            return "B";
        }
        if (grid[0][2] == playerA && grid[1][1] == playerA && grid[2][0] == playerA)
        {
            return "A";
        }
        if (grid[0][2] == playerB && grid[1][1] == playerB && grid[2][0] == playerB)
        {
            return "B";
        }

        // Check for Pending (if any empty spots)
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                if (grid[i][j] == '0')
                {
                    return "Pending"; // There are empty cells, so game is not finished yet
                }
            }
        }

        return "Draw"; // If no winner and no empty cells, it's a draw
    }

    string tictactoe(vector<vector<int>> &moves)
    {
        char grid[SIZE][SIZE] = {{'0', '0', '0'}, {'0', '0', '0'}, {'0', '0', '0'}}; // Initialize grid with '0'

        for (int i = 0; i < moves.size(); i++)
        {
            if (i % 2 == 0)
            {
                // Player A (X)
                grid[moves[i][0]][moves[i][1]] = 'X';
            }
            else
            {
                // Player B (O)
                grid[moves[i][0]][moves[i][1]] = 'O';
            }
        }

        return winner(grid);
    }
};
