class Solution:
  def findPairs(self, nums: List[int], k: int) -> int:
    result = 0
    
    if k == 0:
      counts = Counter(nums)
      for v in counts:
        if counts[v] > 1:
          result += 1
    else:
      hashset = set(nums)
      for v in hashset:
        if v - k in hashset:
          result += 1
        
    return result
  
