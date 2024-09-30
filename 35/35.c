int searchInsert(int *nums, int numsSize, int target)
{
    int i = 0;
    int j = numsSize - 1;

    while (i <= j)
    {
        int mid = i + (j - i) / 2; // Calculate the midpoint

        if (nums[mid] == target)
        {
            return mid; // Target found, return its index
        }
        else if (nums[mid] < target)
        {
            i = mid + 1; // Narrow search to the right half
        }
        else
        {
            j = mid - 1; // Narrow search to the left half
        }
    }

    // If target is not found, i is the insertion point
    return i;
}
