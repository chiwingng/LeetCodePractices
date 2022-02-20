# 80. Remove Duplicates from Sorted Array II

LeetCode Problem Link: <https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/>

## Description

Given an integer array `nums` sorted in **non-decreasing order**, remove some duplicates in-place such that each unique element appears **at most twice**. The **relative order** of the elements should be kept the **same**.

Since it is impossible to change the length of the array in some languages, you must instead have the result be placed in the **first part** of the array nums. More formally, if there are `k` elements after removing the duplicates, then the first `k` elements of `nums` should hold the final result. It does not matter what you leave beyond the first `k` elements.

Return *`k` after placing the final result in the first `k` slots of `nums`*.

Do **not** allocate extra space for another array. You must do this by **modifying the input array in-place** with O(1) extra memory.

**Custom Judge**:

The judge will test your solution with the following code:

    int[] nums = [...]; // Input array
    int[] expectedNums = [...]; // The expected answer with correct length

    int k = removeDuplicates(nums); // Calls your implementation

    assert k == expectedNums.length;
    for (int i = 0; i < k; i++) {
        assert nums[i] == expectedNums[i];
    }

If all assertions pass, then your solution will be **accepted**.


## Constraints

- `1 <= nums.length <= 3 * 10^4`
- `-10^4 <= nums[i] <= 10^4`
- nums is sorted in **non-decreasing** order.

## Solution Thoughts

### Observations

- The input array is already sorted, so all duplicates appear next to each other.
- We need to modify the array in-place, and the remaining part of the array is irrelevant.
   - This means the easiest way is to overwrite the unwanted elements by the needed elements in the later part.

### Logic

- Two pointers are maintained: `loc` and `curr`. `curr` iterates through the whole array and `loc` keeps track of the element which we can overwrite.
- In each iteration:
   - We keep track of the count of duplicated elements `count`.
   - If we have `count <= 2`, that means we want to keep the `nums[curr]` element, so we overwrite `nums[loc]` by `nums[curr]` and move both `loc` and `curr` to the next position.
   - If we have more than two duplicates, we don't want to keep the element, so we just move forward with `curr`.
- At the end, we return `loc` (+1, depending on implementation details) as the length of array kept.

### Complexities

- **Time Complexity** = `O(N)`
   - We iterate through the array exactly once and contant time is used in each loop.

- **Space Complexity** = `O(1)`
   - As required, no extra allocation of arrays were performed. Only two pointers were introduced to keep track of positions.

## Examples

### Example 1

> **Input**: nums = [1,1,1,2,2,3]
>
> **Output**: 5, nums = [1,1,2,2,3,_]
>
> **Explanation**: Your function should return k = 5, with the first five elements of nums being 1, 1, 2, 2 and 3 respectively.
>
> It does not matter what you leave beyond the returned k (hence they are underscores).

### Example 2

> **Input**: nums = [0,0,1,1,1,1,2,3,3]
>
> **Output**: 7, nums = [0,0,1,1,2,3,3,_,_]
>
> **Explanation**: Your function should return k = 7, with the first seven elements of nums being 0, 0, 1, 1, 2, 3 and 3 respectively.
>
> It does not matter what you leave beyond the returned k (hence they are underscores).