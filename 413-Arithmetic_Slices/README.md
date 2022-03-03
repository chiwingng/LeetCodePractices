# 413. Arithmetic Slices

LeetCode Problem Link: <https://leetcode.com/problems/arithmetic-slices/>

## Description

An integer array is called arithmetic if it consists of **at least three elements** and if the difference between any two consecutive elements is the same.

- For example, `[1,3,5,7,9]`, `[7,7,7,7]`, and `[3,-1,-5,-9]` are arithmetic sequences.

Given an integer array `nums`, return *the number of arithmetic* ***subarrays*** *of `nums`*.

A **subarray** is a contiguous subsequence of the array.

## Constraints

- `1 <= nums.length <= 5000`
- `-1000 <= nums[i] <= 1000`

## Solution Thoughts

### Observations and Logic

- We do not need to count every subarrays of an arithmetic sequence one by one:
   - For an arithmetic sequence of length `k`, there are `k-2` subarrays of length 3, ... `k-i+1` subarrays of length `i`. So the total number of arithmetic subarrays is `(k-1)(k-2)/2`.
- So we only need to loop over the longest possible arthmetic sequences in `nums`, and add `(n-1)(n-2)/2` to `result`.
   - The sequences with length 2 are also automatically tackled by the above formula since it will give 0.

### Complexities

- **Time Complexity** = `O(N)` as we traverse the array exactly once, and only `O(1)` operations are performed in the loop.

- **Space Complexity** = `O(1)` as only 4 numbers are stored in the algorithm.

## Examples

### Example 1

> **Input**: nums = [1,2,3,4]
>
> **Output**: 3
>
> **Explanation**: We have 3 arithmetic slices in nums: [1, 2, 3], [2, 3, 4] and [1,2,3,4] itself.

### Example 2

> **Input**: nums = [1]
>
> **Output**: 0
