/***
 *  2. Two Sum
 *  Author: D3lta0ne
 *  Published: 1/26/25
 *
 *  Description:
 *  Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
 *  You may assume that each input would have exactly one solution, and you may not use the same element twice.
 *  You can return the answer in any order.
 */
#include <stdlib.h>
#include <stdio.h>

#define SIZE 2

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    // Allocate memory for the result array
    int* res = (int*)malloc(SIZE * sizeof(int));

    // Check if memory allocation failed
    if (res == NULL) {
        *returnSize = 0;
        return NULL;
    }

    // Set the return size to 2, since the result contains two indices
    *returnSize = SIZE;

    // Loop to find the two numbers whose sum equals target
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                res[0] = i;  // Store the first index
                res[1] = j;  // Store the second index
                return res;  // Return the result array
            }
        }
    }

    // If no solution is found, free the allocated memory and return NULL
    free(res);
    *returnSize = 0;  // Indicate no solution found
    return NULL;  // Return NULL if no solution
}
