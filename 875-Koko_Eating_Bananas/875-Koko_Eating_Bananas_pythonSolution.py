class Solution:
  def minEatingSpeed(self, piles: List[int], h: int) -> int:
    min_k, max_k = 1, max(piles)
    
    while min_k < max_k:
      mid_k = (min_k + max_k)//2
      
      total = 0
      for p in piles:
        total += (p + mid_k - 1)//mid_k
        if total > h:
          break
      
      if total > h:
        min_k = mid_k + 1
      else:
        max_k = mid_k
    
    return min_k
