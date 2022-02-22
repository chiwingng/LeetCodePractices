# 171. Excel Sheet Column Number

LeetCode Problem Link: <https://leetcode.com/problems/excel-sheet-column-number/>

## Description

Given a string `columnTitle` that represents the column title as appear in an Excel sheet, return *its corresponding column number.*

## Constraints

- `1 <= columnTitle.length <= 7`
- `columnTitle` consists only of uppercase English letters.
- `columnTitle` is in the range `["A", "FXSHRXW"]`.

## Solution Thoughts

### Observations

- The first and third constraints are mainly telling us that the result fits in a 32-bit integer.
- The question is equivalent to converting a base-26 number to decimal number.

### Logic

- From left to right:
   - Multiply the current result by 26.
   - Add `c - 'A' + 1` to result. (Since 'A' corresponds to 1 but not 0)

### Complexities

- **Time Complexity** = `O(N)`
   - Single pass through the input string solves the problem, with `O(1)` operations in each iteration.

- **Space Complexity** = `O(1)`
   - Constant auxillary space allocated for intermediate variables like `'A'`.

## Examples

### Example 1

> **Input**: columnTitle = "A"
>
> **Output**: 1

### Example 2

> **Input**: columnTitle = "AB"
>
> **Output**: 28

### Example 3

> **Input**: columnTitle = "ZY"
>
> **Output**: 701
