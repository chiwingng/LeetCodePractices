# 338. Counting Bits

LeetCode Problem Link: <https://leetcode.com/problems/counting-bits/>

## Description

Given an integer `n`, return *an array `ans` of length `n + 1` such that for each `i` (`0 <= i <= n`), `ans[i]` is the* ***number of `1`'s*** *in the binary representation of `i`.*

## Constraints

- `0 <= n <= 10^5`

## Solution Thoughts

### Observations

- The number of bits in `n` is simply the number of bits in `n/2`, if `n` is even.
- We have one more if `n` is odd.

### Logic

- Initialize the result array with size `n+1` with all `0`.
- Starting with `i = 1`, assign the element `result[i]` to be `result[i/2] + (i&1)`. (`i/2` can be replaced by `i >> 1`.)

### Complexities

- **Time Complexity** = `O(N)`
   - The result array is created in time `O(N)`.
   - The array is traversed exactly once -> `O(N)`.

- **Space Complexity** = `O(1)`
   - No auxillary space used except the result array.

## Examples

### Example 1

> **Input**: n = 2
>
> **Output**: [0,1,1]
>
> **Explanation**:
>
> 0 --> 0
>
> 1 --> 1
>
> 2 --> 10

### Example 2

> **Input**: n = 5
>
> **Output**: [0,1,1,2,1,2]
>
> **Explanation**:
>
> 0 -->	0
>
> 1 -->	1
>
> 2 -->	10
>
> 3 --> 11
>
> 4 --> 100
>
> 5 --> 101