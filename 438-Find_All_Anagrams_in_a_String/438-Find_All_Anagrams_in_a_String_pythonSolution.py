from collections import Counter

class Solution:
  def findAnagrams(self, s: str, p: str) -> List[int]:
    if len(p) > len(s):
      return []
    length_p: int = len(p)
    counter: Counter = Counter(p)
    answer: List[int] = []
    for i in range(0, length_p):
      c = s[i]
      counter[c] = counter.get(c, 0) - 1
      if counter[c] == 0:
        del counter[c]
    if not counter:
      answer.append(0)
      
    for i in range(length_p, len(s)):
      c = s[i]
      counter[c] = counter.get(c, 0) - 1
      if counter[c] == 0:
        del counter[c]
      old = s[i - length_p]
      counter[old] = counter.get(old, 0) + 1
      if counter[old] == 0:
        del counter[old]
      
      if not counter:
        answer.append(i - length_p + 1)
    
    return answer
