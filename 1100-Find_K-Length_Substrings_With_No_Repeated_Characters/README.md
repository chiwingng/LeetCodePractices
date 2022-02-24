# 1100. Find K-Length Substrings With No Repeated Characters

LeetCode Problem Link: <https://leetcode.com/problems/find-k-length-substrings-with-no-repeated-characters/>

## Description

Given a string `s` and an integer `k`, return *the number of substrings in `s` of length `k` with no repeated characters.*

## Constraints

- `1 <= s.length <= 10^4`
- `s` consists of lowercase English letters.
- `1 <= k <= 10^4`

## Solution Thoughts

### Observations

- If we would solve the problem using brute-force, we need to count a set of character frequencies for all substrings of length `k`.
   - In this process we are double-counting a lot of characters in the middle of the string.
- Therefore a sliding window approach is better to avoid redundant work.
- The problem states that the input string contains only lowercase English characters:
   - For `k > 26` or `k > s.length`, the problem statement is clearly impossible, so we can skip the checking process and directly return `0`.
   - A vector of length 26 is enough for storing the required information, but as the problem may extend to characters other than lowercase English characters, a more general storage approach of hashmap can be used.

### Logic

- First check for the two obvious failing case.
- Maintain a hashmap `char_loc` of characters mapping to locations.
- Initialize `start` and `end` to 0.
- While `end < s.length`:
   - If `s[end]` is seen before, we will eliminate all character information before `char_loc[s[end]]` and move `start` to `char_loc[s[end]] + 1`.
   - Register `char_loc[s[end]]` as `end`
   - If the length between `start` and `end` is exactly `k`, we found a valid substring. Increment `result`, unregister `s[start]` in the hashmap and increment `start`.
   
### Complexities

Let `N` be the length of `s`.

- **Time Complexity** = `O(N)`
   - Each character is traversed at most twice in the sliding window process, in which only `O(1)` insertion and lookup actions were taken.

- **Space Complexity** = `O(k)`
   - At most `k` characters are kept in the hashmap, which is upper-bounded by 26. So in this case it can be considered as `O(1)`.

## Examples

### Example 1

> **Input**: s = "havefunonleetcode", k = 5
>
> **Output**: 6
>
> **Explanation**: There are 6 valid substrings, they are: 'havef','avefu','vefun','efuno','etcod','tcode'.

### Example 2

> **Input**: s = "home", k = 5
>
> **Output**: 0
>
> **Explanation**: Notice k can be larger than the length of s. In this case, it is not possible to find any substring.
