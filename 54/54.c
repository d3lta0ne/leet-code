/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *spiralOrder(int **matrix, int matrixSize, int *matrixColSize, int *returnSize)
{
    // Allocate memory for result array
    int m = matrixSize;
    int n = *matrixColSize;
    int *result = (int *)malloc(m * n * sizeof(int));

    int topBorder = 0;
    int leftBorder = 0;
    int rightBorder = n - 1;
    int bottomBorder = m - 1;

    int idx = 0;

    // Traverse the matrix in spiral order
    while (topBorder <= bottomBorder && leftBorder <= rightBorder)
    {
        // Traverse from left to right along the top row
        for (int y = leftBorder; y <= rightBorder; y++)
        {
            result[idx++] = matrix[topBorder][y];
        }
        topBorder++;

        // Traverse from top to bottom along the right column
        for (int x = topBorder; x <= bottomBorder; x++)
        {
            result[idx++] = matrix[x][rightBorder];
        }
        rightBorder--;

        if (topBorder <= bottomBorder)
        {
            // Traverse from right to left along the bottom row
            for (int y = rightBorder; y >= leftBorder; y--)
            {
                result[idx++] = matrix[bottomBorder][y];
            }
            bottomBorder--;
        }

        if (leftBorder <= rightBorder)
        {
            // Traverse from bottom to top along the left column
            for (int x = bottomBorder; x >= topBorder; x--)
            {
                result[idx++] = matrix[x][leftBorder];
            }
            leftBorder++;
        }
    }

    *returnSize = m * n; // Total number of elements
    return result;
}
