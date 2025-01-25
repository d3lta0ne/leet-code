/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    int n = matrixSize;
    int m = *matrixColSize;
    
    int min = 0;
    if ( m >= n ) {
        min = n;
    } 
    else { min = m; }

    int phase = 0;
    *returnSize = m * n;

    int* result = (int*)malloc(matrixSize * (*matrixColSize) * sizeof(int));
    int idx = 0;
    while (phase < (min + 1) / 2) {
        for (int i = phase; i < m - phase; i++) {
            result[idx] = matrix[phase][i];
            idx++;
        }
        for (int i = phase + 1; i < n - phase; i++) {
            result[idx] = matrix[i][m - 1 - phase];
            idx++;
        }
        if (n - 1 - phase > phase) {
            for (int i = m - 2 - phase; i > phase - 1; i--) {
                result[idx] = matrix[n - 1 - phase][i];
                idx++;
            }
        }
        if (m - 1 - phase > phase) {
            for (int i = n - 2 - phase; i > phase; i--) {
                result[idx] = matrix[i][phase];
                idx++;
            }
        }
        phase = phase + 1;
    }

    return result;
}