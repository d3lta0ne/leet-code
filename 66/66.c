/**
 * /***
 * 66. Plus One
 * Author: D3lta0ne
 * Published: 1/23/25
 *
 * Description:
 * You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.
 * Increment the large integer by one and return the resulting array of digits.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *plusOne(int *digits, int digitsSize, int *returnSize)
{
    int i = digitsSize - 1;
    while (i >= 0 && digits[i] == 9)
    {
        digits[i] = 0;
        i--;
    }

    if (i == -1)
    {
        *returnSize = digitsSize + 1;
        int *res = (int *)calloc((*returnSize) * sizeof(int), sizeof(int));
        res[0] = 1;
        return res;
    }

    digits[i]++;
    *returnSize = digitsSize;
    return digits;
}