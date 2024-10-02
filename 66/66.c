/**
 * /***
 * 66. Plus One
 * Author: D3lta0ne
 * Published: 10/1/24
 *
 * Description:
 * You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.
 * Increment the large integer by one and return the resulting array of digits.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    // Allocate space for the new digits array
    int* result = (int*)malloc((digitsSize + 1) * sizeof(int));
    int carry = 1; // We start with a carry of 1 since we're adding one

    // Iterate from the last digit to the first
    for (int i = digitsSize - 1; i >= 0; i--) {
        int sum = digits[i] + carry;
        if (sum >= 10) {
            result[i + 1] = sum % 10; // Store the last digit
            carry = 1; // Carry remains 1
        } else {
            result[i] = sum; // No carry needed
            carry = 0; // No carry going forward
        }
    }

    // If there's still a carry after the most significant digit
    if (carry) {
        result[0] = 1; // The new most significant digit is 1
        *returnSize = digitsSize + 1; // New size
    }
    else
    {
        for (int i = 0; i < digitsSize-1; i++) {
            result[i] = result[i + 1];
        }
        *returnSize = digitsSize; // Old size
    }

    return result;
}