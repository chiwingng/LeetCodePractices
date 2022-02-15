class Solution:
  def fourSumCount(self, A: List[int], B: List[int], C: List[int], D: List[int]) -> int:
    cnt = 0
    m = collections.defaultdict(int)
    for a in A:
      for b in B:
        m[a + b] += 1
        
    for c in C:
      for d in D:
        cnt += m[-(c + d)]
        
    return cnt
