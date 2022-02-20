# 532. K-diff Pairs in an Array

LeetCode Problem Link: <https://leetcode.com/problems/k-diff-pairs-in-an-array/>

## Description

Given an array of integers `nums` and an integer `k`, return *the number of* ***unique*** *k-diff pairs in the array*.

A **k-diff** pair is an integer pair `(nums[i], nums[j])`, where the following are true:

- `0 <= i, j < nums.length`
- `i != j`
- `|nums[i] - nums[j]| == k`

Notice that `|val|` denotes the absolute value of `val`.

## Constraints

- `1 <= nums.length <= 10^4`
- `-10^7 <= nums[i] <= 10^7`
- `0 <= k <= 10^7`

## Solution Thoughts

### Observations

- Only **unique** *value* pairs are counted, however there can be a case where `k = 0`, when we need to know if each number appeared more than once.
- We need unique pairs, so when searching for the complement of any element, we only need to search for one direction (either up: `n + k` or down: `n - k`).

### Logic

- Initialize `result` to be 0.
- Separate into two cases:
   - `k = 0`:
      - Maintain a counter hashmap
      - Loop over all elements to increment the counter hashmap
      - When any counter reaches 2, increment the result, since we have a pair of same values that have difference 0.
   - `k > 0`:
      - Create a value hashset from the input elements.
      - For any value `n` in the hashset `unique_nums`, increment `result` if we find `n - k` (or equivalently `n + k`) in the hashset.
      
### Complexities

- **Time Complexity** = `O(N)`
   - For the `k = 0` case, we loop over the inputs exactly once, hashmap lookup and insertion both cost `O(1)` time, in total `O(N)` time.
   - For the `k > 0` case, we loop over the inputs once to create the hashset, then loop over all unique elements to perform counting, which sums up to `O(2N) = O(N)`.

- **Space Complexity** = `O(N)`
   - The hashmap/hashset stores at most `N` elements, so costing `O(N)` memory.

## Examples

### Example 1

> **Input**: nums = [3,1,4,1,5], k = 2
>
> **Output**: 2
>
> **Explanation**: There are two 2-diff pairs in the array, (1, 3) and (3, 5).
>
> Although we have two 1s in the input, we should only return the number of unique pairs.

### Example 2

> **Input**: nums = [1,2,3,4,5], k = 1
>
> **Output**: 4
>
> **Explanation**: There are four 1-diff pairs in the array, (1, 2), (2, 3), (3, 4) and (4, 5).

### Example 3

> **Input**: nums = [1,3,1,5,4], k = 0
>
> **Output**: 1
>
> **Explanation**: There is one 0-diff pair in the array, (1, 1).
