# 438. Find All Anagrams in a String

LeetCode Problem Link: <https://leetcode.com/problems/find-all-anagrams-in-a-string/>

## Description

Given two strings `s` and `p`, return *an array of all the start indices of `p`'s anagrams in `s`*. You may return the answer in **any order**.

An **Anagram** is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

## Constraints

- `1 <= s.length, p.length <= 3 * 10^4`
- `s` and `p` consist of lowercase English characters

## Solution Thoughts

### Observations

- For any anagram of a given string, the counts of characters in the string and its anagram should be identical.
- Therefore a sliding window of counts would solve the problem.
- To enhance performance, if `p` is longer than `s`, an empty list can be returned immediately.
- As an extension of this problem, the input strings may contain letters that are not lowercase English characters, therefore the vector solution is not extensible.

### Logic

- Initialize the hashmap of character counts by the characters in `p`.
- In any of the following steps, if the hashmap is empty (i.e. all character counts becomes zero), a valid anagram is found and the starting index is pushed into the `result` list.
- Decrement the character counts by the first `p.length` characters in `s`.
- For each of the indices `i`:
   - Maintain a sliding window of size `p.length`, decrement the new character at current index `i` and increment the character released at index `i - p.length`.
   - After updating the hash map, if the count is zero, we can erase it from the map.
   - If the map is empty, that means the character sets are equal, push the starting index `i - p.length + 1` to `result` array
- Return `result`

### Complexities

Let `N_s` and `N_p` be the lengths of `s` and `p` respectively, and `K_s`, `K_p` be the number of distinct characters in `s` and `p` respectively.

- **Time Complexity** = `O(N_s)`
   - One pass for `p` and `s` are performed. which costs `O(N_p + N_s)`. Since we skip the pass when `N_p > N_s`, we have complexity `O(N_s)`.

- **Space Complexity** = `O(max(K_s, K_p)) = O(26) = O(1)`
   - The hash map will contain at most `K_s/p` elements. As these elements can only be lowercase English characters, `K_s/p` are bounded by 26.

## Examples

### Example 1

> **Input**: s = "cbaebabacd", p = "abc"
>
> **Output**: [0,6]
>
> **Explanation**:
>
> The substring with start index = 0 is "cba", which is an anagram of "abc".
>
> The substring with start index = 6 is "bac", which is an anagram of "abc".

### Example 2

> **Input**: s = "abab", p = "ab"
>
> **Output**: [0,1,2]
>
> **Explanation**:
>
> The substring with start index = 0 is "ab", which is an anagram of "ab".
>
> The substring with start index = 1 is "ba", which is an anagram of "ab".
>
> The substring with start index = 2 is "ab", which is an anagram of "ab".