class Solution:
  def intervalIntersection(self, firstList: List[List[int]], secondList: List[List[int]]) -> List[List[int]]:
    i1, i2, l1, l2 = 0, 0, len(firstList), len(secondList)
    result = []
    while i1 < l1 and i2 < l2:
      low, high = max(firstList[i1][0], secondList[i2][0]), min(firstList[i1][1], secondList[i2][1])
      if low <= high:
        result.append([low, high])
      if (secondList[i2][1] == high):
        i2 += 1
      else:
        i1 += 1
    return result
