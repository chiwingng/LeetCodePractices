# 258. Add Digits

LeetCode Problem Link: <https://leetcode.com/problems/add-digits/>

## Description

Given an integer `num`, repeatedly add all its digits until the result has only one digit, and return it.

## Constraints

- `0 <= num <= 2^31 - 1`

## Solution Thoughts

### Observations

Let's denote the transformation on the number `n` as `f(n)`.
- The problem is clearly related to `modulo 9` because adding up digits is changing `d * 10^i` to `d`, between which the difference is `d * (10^i - 1) = d * 9...9`(`i` digits).
   - Therefore `f(n) = n (mod 9)`
- Since we are reducing the number repeatedly until the result has only one digit, it is effectively taking the remainder of `n` divided by 9, with exception:
   - When we end up with 9, we will stop. So the only case when we have result 0 is we have input 0.
   - Other multiples of 9 will result in 9, and all non-multiples of 9 will result in their remainders.
- The non-zero cases can be combined into one: `1 + (n - 1) % 9` as multiples of 9 will get `1 + 8 = 9` and the other non-multiples will get the same result.

### Logic

- If `num == 0`, return 0
- Else: return `1 + (n - 1) % 9`

### Complexities

- **Time Complexity** = `O(1)`
   - No loop is performed, only constant operations

- **Space Complexity** = `O(1)`

## Examples

### Example 1

> **Input**: num = 38
>
> **Output**: 2
>
> **Explanation**: The process is
>
> 38 --> 3 + 8 --> 11
>
> 11 --> 1 + 1 --> 2 
>
> Since 2 has only one digit, return it.

### Example 2

> **Input**: num = 0
>
> **Output**: 0