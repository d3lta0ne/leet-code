/***
 * 35. Search Insert Position
 * Author: D3lta0ne
 * Published: 9/30/24
 *
 * Description:
 * Given a sorted array of distinct integers and a target value, return the index if the target is found.
 * If not, return the index where it would be if it were inserted in order.
 * You must write an algorithm with O(log n) runtime complexity.
 */

int searchInsert(int *nums, int numsSize, int target)
{
    if (!nums || numsSize == 0)
    {
        return 0;
    }

    int i = 0;
    int j = numsSize - 1;
    while (i <= j)
    {
        if (target == nums[i])
        {
            return i;
        }
        else if (target < nums[i / 2])
        {
            j = (j / 2) + 1;
        }
        else
        {
            i = (j / 2) + 1;
        }
    }
    return i;
}