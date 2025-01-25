#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        const int VISITED = 101;
        int rows = matrix.size(), columns = matrix[0].size();
        // Four directions that we will move: right, down, left, up.
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        // Initial direction: moving right.
        int currentDirection = 0;
        // The number of times we change the direction.
        int changeDirection = 0;
        // Current place that we are at is (row, col).
        // row is the row index; col is the column index.
        int x = 0, y = 0;
        // Store the first element and mark it as visited.
        vector<int> result = {matrix[0][0]};
        matrix[0][0] = VISITED;
        while (changeDirection < 2) {
            while (0 <= x + directions[currentDirection][0] &&
                   x + directions[currentDirection][0] < rows &&
                   0 <= y + directions[currentDirection][1] &&
                   y + directions[currentDirection][1] < columns &&
                   matrix[x + directions[currentDirection][0]]
                         [y + directions[currentDirection][1]] != VISITED) {
                // Reset this to 0 since we did not break and change the
                // direction.
                changeDirection = 0;
                // Calculate the next place that we will move to.
                x += directions[currentDirection][0];
                y += directions[currentDirection][1];
                result.push_back(matrix[x][y]);
                matrix[x][y] = VISITED;
            }
            // Change our direction.
            currentDirection = (currentDirection + 1) % 4;
            // Increment change_direction because we changed our direction.
            changeDirection++;
        }
        return result;
    }
};