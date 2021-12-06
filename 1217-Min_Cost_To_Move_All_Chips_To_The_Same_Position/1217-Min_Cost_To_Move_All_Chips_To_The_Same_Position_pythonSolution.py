class Solution:
  def minCostToMoveChips(self, position: List[int]) -> int:
    oddCount = 0
    for p in position:
      oddCount += p % 2
    return min(oddCount, len(position) - oddCount)
