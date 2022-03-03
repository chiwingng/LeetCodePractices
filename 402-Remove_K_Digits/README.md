# 402. Remove K Digits

LeetCode Problem Link: <https://leetcode.com/problems/remove-k-digits/>

## Description

Given string num representing a non-negative integer `num`, and an integer `k`, return *the smallest possible integer after removing `k` digits from `num`.*

## Constraints

- `1 <= k <= num.length <= 10^5`
- `num` consists of only digits.
- `num` does not have any leading zeros except for the zero itself.

## Solution Thoughts

### Observations and Logic

- The brute force solution would result in exponential (or factorial) time complexity, as there are `C^N_k` possible ways to remove `k` digits from `num` with `N` digits.
- The problem can be solved using the greedy algorithm:
   - The final number will have length `N-k`.
   - If the `i`th digit from the left is larger than the `i+1`th, it should be removed because it will gain us at least `10^(N-k-i)`, which is not possible for any digits to its right.
   - Therefore we can assure that a single pass greedy algorithm will work.
   - It is possible that after the single pass, there are remaining `k'` digits to be removed. In this case since all digits are in ascending order from left to right, we can simply remove the last `k'` digits.
   - It is also possible that in the final result there are leading zeros, we can do another pass to remove them.

### Logic

- A simple check to see if there are more digits to remove than we have, if true then we can simply return `0`.
- Maintain a `result` stack. (In C++ a string is a vector, which is naturally a stack)
- Loop over the input `num` string from the left:
   - For each character `cr` in the `result` stack, check if it is larger than the current character `cn` in `num`. If true we will remove `cr` from the stack and decrement `k`.
      - Stop if we exhausted the stack, or if we are done removing digits (`k=0`), or we see `cr < cn`.
   - After removing all larger digits from the stack, we push `cn` into the stack and go to the next `cn`.
- Next we determine the starting point of the result string by skipping all leading zeros.
- Check if after removing the leading zeros and the last `k` digits left to remove (`k` might still be larger than `0` at this point), we still have a valid string
   - If we removed more digits than we have, we return `0`.
   - Otherwise we return the part of result after removing the leading zeros and last `k` digits.

### Complexities

Assume the length of input string is `N`, and there are `z` leading zeros in the output string to remove.
- **Time Complexity** = `O(N)`
   - We perform the removing action for one whole pass for the input string, which goes over every elements at most twice (once insertion, once delete). -> `O(N+k) = O(N)`. (we skip the process if `k>=N`)
   - We perform leading zero detection for the resulting string, which is `O(z) <= O(N)`
   - We finally build the resulting substring of length `N-k-z`, so TC is `O(N-k-z) = O(N)`.

- **Space Complexity** = `O(N)`
   - We hold all input digits in the `result` stack in the worst case.

## Examples

### Example 1

> **Input**: num = "1432219", k = 3
>
> **Output**: "1219"
>
> **Explanation**: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.

### Example 2

> **Input**: num = "10200", k = 1
>
> **Output**: "200"
>
> **Explanation**: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.

### Example 3

> **Input**: num = "10", k = 2
>
> **Output**: "0"
>
> **Explanation**: Remove all the digits from the number and it is left with nothing which is 0.
