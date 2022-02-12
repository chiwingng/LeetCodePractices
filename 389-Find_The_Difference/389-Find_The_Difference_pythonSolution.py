class Solution_1:
  from collections import Counter
  
  def findTheDifference(self, s: str, t: str) -> str:
  counter_s = Counter(s)
  
  for c in t:
    if c not in counter_s or counter_s[c] == 0:
      return c
    else:
      counter_s[c] -= 1

class Solution_2:
  def findTheDifference(self, s: str, t: str) -> str:
    ch = 0
    for c in s:
      ch ^= ord(c)

    for c in t:
      ch ^= ord(c)

    return chr(ch)
