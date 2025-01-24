/*
Algorithm

    We use two lists, rows and cols of size n, to represent each row and column. We also use two numbers, diag and anti_diag, to represent the diagonal value and anti-diagonal value, respectively.

    Set the value of player A as 1 and the value of player B as -1.

    For each new move [row, col], add the player's value to rows[row] and cols[col]. If [row, col] is on the diagonal or anti-diagonal, then add the player's value to diag or anti_diag as well.

    Then, check if this move meets any winning condition:
        Check if all cells in the current row contain characters from this player. To do so, we just need to check if the absolute value of rows[row] equals n.
        Check if all cells in the current column contain characters from this player. To do so, we just need to check if the absolute value of cols[col] equals n.
        Check if this move is on the diagonal; that is if row equals col. If so, check if the absolute value of diag equals n.
        Check if this move is on the anti-diagonal; that is if row + col equals n - 1. If so, check if the absolute value of anti_diag equals n.

    If there is no winner after all of the moves have been played, we will check if the entire board is filled. If so, return "Draw", otherwise return "Pending", meaning the game is still on. To determine if the entire board is filled, check if the length of moves equals the number of cells on the n by n board.

*/

#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    string tictactoe(vector<vector<int>> &moves)
    {

        // n stands for the size of the board, n = 3 for the current game.
        int n = 3;

        // Use rows and cols to record the value on each row and each column.
        // diag1 and diag2 to record value on diagonal or anti-diagonal.
        vector<int> rows(n), cols(n);
        int diag = 0;
        int anti_diag = 0;

        // Two players having value of 1 and -1, player_1 with value = 1 places first.
        int player = 1;

        for (vector<int> move : moves)
        {

            // Get the row number and column number for this move.
            int row = move[0];
            int col = move[1];

            // Update the row value and column value.
            rows[row] += player;
            cols[col] += player;

            // If this move is placed on diagonal or anti-diagonal,
            // we shall update the relative value as well.
            if (row == col)
            {
                diag += player;
            }
            if (row + col == n - 1)
            {
                anti_diag += player;
            }

            // Check if this move meets any of the winning conditions.
            if (abs(rows[row]) == n || abs(cols[col]) == n ||
                abs(diag) == n || abs(anti_diag) == n)
            {
                return player == 1 ? "A" : "B";
            }

            // If no one wins so far, change to the other player alternatively.
            // That is from 1 to -1, from -1 to 1.
            player *= -1;
        }

        // If all moves are completed and there is still no result, we shall check if
        // the grid is full or not. If so, the game ends with draw, otherwise pending.
        return moves.size() == n * n ? "Draw" : "Pending";
    }
};