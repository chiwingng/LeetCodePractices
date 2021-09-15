class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        index = {}
        start, end, n_char, result = 0, 0, len(s), 0
        for c in s:
            prev_index = index.get(c, -1)
            if prev_index >= start:
                # this character is repeated
                # previous non-repeating substring is [start, end)
                result = max(result, end - start)
                # move start to prev_index + 1
                start = prev_index + 1
            # register current character index
            index[c] = end
            # increment end
            end += 1
        return max(result, end - start)
