# 454. 4Sum II

LeetCode Problem Link: <https://leetcode.com/problems/4sum-ii/>

## Description

Given four integer arrays `nums1`, `nums2`, `nums3`, and `nums4` all of length `n`, return the number of tuples `(i, j, k, l)` such that:

- `0 <= i, j, k, l < n`
- `nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0`

## Constraints

- `nums1.length == nums2.length == nums3.length == nums4.length == n`
- `1 <= n <= 200`
- `-2^28 <= nums1[i], nums2[i], nums3[i], nums4[i] <= 2^28`

## Solution Thoughts

### Observations

- A brute force loop requires `O(N^3)` time complexity.
- Grouping the 4 arrays into 2 sets can reduce the complexity to `O(N^2)`.
- Sum of 2 elements can be up to `2^56`, which exceeds the size `int` data type can hold. So it needs to be casted to `long`.

### Logic

- Create a hash map `counts` of counts of pair-wise sums of elements in (`nums1`, `nums2`).
- For every pair of values `(n3, n4)` in `nums3` and `nums4`, increase `result` by `counts[-n3-n4]`

### Complexities

- **Time Complexity** = `O(N^2)`
   - Looping over the first pair of arrays to build the hash map require `O(N^2)` time.
   - Looping over one of the hash maps takes `O(K)` time, where `K` is the number of unique pair-wise sums in the hash map. In worst case `K = N^2`, so also `O(N^2)` time complexity.

- **Space Complexity** = `O(K) = O(N^2)`
   - It takes `O(K) = O(N^2)` space to store the hash map.

## Examples

### Example 1

> **Input**: nums1 = [1,2], nums2 = [-2,-1], nums3 = [-1,2], nums4 = [0,2]
>
> **Output**: 2
>
> **Explanation**:
>
> The two tuples are:
>
> 1. (0, 0, 0, 1) -> nums1[0] + nums2[0] + nums3[0] + nums4[1] = 1 + (-2) + (-1) + 2 = 0
>
> 2. (1, 1, 0, 0) -> nums1[1] + nums2[1] + nums3[0] + nums4[0] = 2 + (-1) + (-1) + 0 = 0

### Example 2

> **Input**: nums1 = [0], nums2 = [0], nums3 = [0], nums4 = [0]
>
> **Output**: 1
