class Solution:
  def numKLenSubstrNoRepeats(self, s: str, k: int) -> int:
    if k > 26 or k > len(s):
      return 0
    char_locs = {}
    result, start = 0, 0
    for end in range(0, len(s)):
      c = s[end]
      while start <= char_locs.get(c, -1):
        char_locs[s[start]] = -1
        start += 1
      char_locs[c] = end
      if end - start + 1 == k:
        result += 1
        char_locs[s[start]] = -1
        start += 1
    return result
