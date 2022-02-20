# 560. Subarray Sum Equals K

LeetCode Problem Link: <https://leetcode.com/problems/subarray-sum-equals-k/>

## Description

Given an array of integers `nums` and an integer `k`, return *the total number of subarrays whose sum equals to `k`.*

## Constraints

- `1 <= nums.length <= 2 * 10^4`
- `-1000 <= nums[i] <= 1000`
- `-10^7 <= k <= 10^7`

## Solution Thoughts

### Observations

- Sum of a subarray can be computed by the difference between two prefix sums:
   - `Sum[i,j] = Sum[0,j] - Sum[0, i-1]` (defining `Sum[0, -1] = 0`)
- Only the count of subarrays is needed, not the arrays themselves.

### Logic

- Initialize a prefix-sum count hashmap with `count[0] = 1` indicating the same condition as `Sum[0, -1] = 0`.
- Loop over each number in order:
   - Compute the prefix sum `prefix` up to this number.
   - Find the number of prefix-sums before that has the amount `prefix - k` (so that the difference is `k`) and add to the final result
   - Increment the hashmap count of `prefix` by 1.

### Complexities

- **Time Complexity** = `O(N)`
   - One-pass loop over all elements in `nums` with one lookup and one insertion in each iteration.
   - Hashmap insert and loopup are both amortized `O(1)` operations

- **Space Complexity** = `O(N)`
   - The hashmap will hold `D = number of distinct prefix-sums` entries.
   - It is not uncommon that all prefix-sums are distinct, in such case `D = N`.

## Examples

### Example 1

> **Input**: nums = [1,1,1], k = 2
>
> **Output**: 2

### Example 2

> **Input**: nums = [1,2,3], k = 3
>
> **Output**: 2
