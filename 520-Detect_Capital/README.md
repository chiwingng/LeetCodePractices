# 520. Detect Capital

LeetCode Problem Link: <https://leetcode.com/problems/detect-capital/>

## Description

We define the usage of capitals in a word to be right when one of the following cases holds:

- All letters in this word are capitals, like `"USA"`.
- All letters in this word are not capitals, like `"leetcode"`.
- Only the first letter in this word is capital, like `"Google"`.

Given a string `word`, return `true` if the usage of capitals in it is right.

## Constraints

- `1 <= word.length <= 100`
- `word` consists of lowercase and uppercase English letters.

## Solution Thoughts

### Observations
- If we define `tail` as the substring of `word` starting at the second character, the usage of capital is correct if:
   - `tail` is all non-capitals, OR
   - `tail` is all capital AND `word` starts with capital.

### Logic

- Check if `word` starts with capital letter.
- Loop over the rest of `word` to check if `tail`:
   - has no capitals
   - consists of all capitals

### Complexities

- **Time Complexity** = `O(N)`
   - Single loop over all characters does the job.

- **Space Complexity** = `O(1)`
   - Only 3 booleans are stored.

## Examples

### Example 1

> **Input**: word = "USA"
>
> **Output**: true

### Example 2

> **Input**: word = "FlaG"
>
> **Output**: false
