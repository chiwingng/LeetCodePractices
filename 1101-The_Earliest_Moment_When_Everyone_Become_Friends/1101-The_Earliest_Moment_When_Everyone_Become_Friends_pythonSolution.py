class UnionFind:
  def __init__(self, n: int):
    self.size = [1] * n
    self.parent = [i for i in range(0,n)]
  
  def findParent(self, i: int) -> int:
    while self.parent[i] != i:
      # path compression
      self.parent[i] = self.parent[self.parent[i]]
      i = self.parent[i]
    return i
    
  def union(self, i:int, j:int) -> int:
    if i == j:
      return 0
    pi, pj = self.findParent(i), self.findParent(j)
    if pi == pj:
      return 0
    if self.size[pj] < self.size[pi]:
      pi, pj = pj, pi
    self.parent[pi] = pj
    self.size[pj] += self.size[pi]
    return self.size[pj]
    
class Solution:
  def earliestAcq(self, logs: List[List[int]], n: int) -> int:
    logs.sort(key = lambda x : x[0])
    
    uf = UnionFind(n)
    
    for time, i, j in logs:
      if uf.union(i, j) == n:
        return time
    
    return -1
