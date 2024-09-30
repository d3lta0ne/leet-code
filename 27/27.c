/***
 * 26. Remove Element
 * Author: D3lta0ne
 * Published: 9/30/24
 *
 * Description:
 * Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The order of the elements may be changed. Then return the number of elements in nums which are not equal to val.
 * Consider the number of elements in nums which are not equal to val be k, to get accepted, you need to do the following things:
 * Change the array nums such that the first k elements of nums contain the elements which are not equal to val. The remaining elements of nums are not important as well as the size of nums.
 * Return k.
 */

int removeElement(int *nums, int numsSize, int val)
{
    int j = 0; // j will track the position of the next element that isn't val
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] != val)
        {
            nums[j] = nums[i]; // Move the non-val element to the front
            j++;
        }
    }
    return j; // j is the count of elements that are not equal to val
}
