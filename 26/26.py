"""
 * 26. Remove Duplicates from Sorted Array
 * Author: D3lta0ne
 * Published: 9/7/24
 *
 * Description:
 * Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same. Then return the number of unique elements in nums.
 * Consider the number of unique elements of nums to be k, to get accepted, you need to do the following things:
 * Change the array nums such that the first k elements of nums contain the unique elements in the order they were present in nums initially. The remaining elements of nums are not important as well as the size of nums.
 * Return k.
"""
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        # Edge case: if the list is empty, return 0
        if not nums:
            return 0
        
        # Initialize the index for the position of unique elements
        k = 1
        
        # Iterate over the array starting from the second element
        for i in range(1, len(nums)):
            # If the current element is different from the previous one
            if nums[i] != nums[i - 1]:
                # Place the unique element in the correct position
                nums[k] = nums[i]
                # Move the index for unique elements
                k += 1
        
        # Return the number of unique elements
        return k