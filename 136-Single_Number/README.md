# 136. Single Number

LeetCode Problem Link: <https://leetcode.com/problems/single-number/>

## Description

Given a **non-empty** array of integers `nums`, every element appears *twice* except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space.

## Constraints

- `1 <= nums.length <= 3 * 10^4`
- `-3 * 10^4 <= nums[i] <= 3 * 10^4`
- Each element in the array appears twice except for one element which appears only once.

## Solution Thoughts

### Observations

- One can make use of hashset, suming and sorting to solve the problem, but they all fail either the TC (O(N)) or SC (O(1)) requirements.
- XOR provides a simple way to solve this problem:
   - `a^a = 0`, `a^b = b^a` ensures if we perform XOR on all the elements, all pairs of duplicated elements will vanish, leaving the single element out.

### Logic

- Starting with `single = 0`, perform XOR on `single` and each element of array, the final `single` will be the single element.

### Complexities

- **Time Complexity** = `O(N)`
   - The array is traversed exactly once with `O(1)` operations in each iteration.

- **Space Complexity** = `O(1)`
   - No auxillary space is used except for the final result.

## Examples

### Example 1

> **Input**: [2,2,1]
>
> **Output**: 1

### Example 2

> **Input**: [4,1,2,1,2]
>
> **Output**: 4

### Example 3

> **Input**: [1]
>
> **Output**: 1