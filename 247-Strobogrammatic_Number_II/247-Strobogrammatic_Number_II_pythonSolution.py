class Solution:
  self_matches = ['0', '1', '8']
  possible_chars = {'0': '0', '1': '1', '6': '9', '8': '8', '9': '6'};
  result = []
  def backtrack(self, curr: List[str], left: int, right: int):
    if left > right:
      self.result.append(''.join(curr))
    elif left == right:
      for c in self.self_matches:
        curr[left] = c
        self.result.append(''.join(curr))
    else:
      for k, v in self.possible_chars.items():
        if k == '0' and left == 0:
          continue
        curr[left] = k
        curr[right] = v
        self.backtrack(curr, left + 1, right - 1)
        
  def findStrobogrammatic(self, n: int) -> List[str]:
    self.result = []
    curr = [',' for _ in range(n)]
    self.backtrack(curr, 0, n-1)
    return self.result
