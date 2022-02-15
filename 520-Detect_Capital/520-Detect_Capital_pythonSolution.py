class Solution:
  def detectCapitalUse(self, word: str) -> bool:
    startWithCapital = word[0].isupper()
    tailNoCapital, tailAllCapital = True, True
    
    for c in word[1:]:
      if c.isupper():
        tailNoCapital = False
      else:
        tailAllCapital = False
    
    return tailNoCapital or (tailAllCapital and startWithCapital)

class Solution_Alt:
  def detectCapitalUse(self, word: str) -> bool:
    return word.isupper() or word.islower() or word.istitle()
