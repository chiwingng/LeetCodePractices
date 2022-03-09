# 247. Strobogrammatic Number II

LeetCode Problem Link: <https://leetcode.com/problems/strobogrammatic-number-ii/>

## Description

Given an integer `n`, return all the **strobogrammatic numbers** that are of length `n`. You may return the answer in **any order**.

A **strobogrammatic number** is a number that looks the same when rotated `180` degrees (looked at upside down).

## Constraints

- `1 <= n <= 14`

## Solution Thoughts

### Observations

- The only numbers that are still a number when rotated `180` degrees are: '0', '1', '6', '8', '9'.
- Among these numbers only '0', '1', '8' match themselves when rotated.
- 2 cases in filling numbers:
   - Even number of digits: `n % 2 == 0`
      - We can simply fill digits in pairs.
   - Odd number of digits: `n % 2 == 1`
      - We fill digits in pairs, until we reach the center.
      - At the center we can only fill in self-matching digits.
- One more thing to check:
   - The number cannot start with 0!

### Logic

- Construct a string `curr` with length `n` and a vector/array of strings `result`.
- We perform backtracking to construct all possible strings:
   - Starting with both ends of the string
   - In each iteration check:
      - If `left` is larger than `right`, that means we finished constructing a valid string, push `curr` into `result`.
      - `left == right`, which means we are at the center of an odd-length string, we can only put in self-matching digits.
      - If the above two do not hold, we need to insert a pair of digits to `left` and `right`.
         - Skip if we are at the very end and we are adding '0'!

### Complexities


- **Time Complexity** = `O(N*5^{N/2})`
   - We need to construct a string for every possible strobogrammatic number, which takes `O(N)` time for each.
   - There are `5^{N/2}` (for even `N`) or `3*5^{N/2}` (for odd `N`) possible strobogrammatic numbers.

- **Space Complexity** = `O(N)`
   - The backtrack stack has depth `N/2`.
   - The temporary string has length `N`.
   - Number of possible characters are constant.

## Examples

### Example 1

> **Input**: n = 2
>
> **Output**: ["11","69","88","96"]

### Example 2

> **Input**: n = 1
>
> **Output**: ["0","1","8"]

