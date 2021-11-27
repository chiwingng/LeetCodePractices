import sys
class Solution:
  def maxSubArray(self, nums: List[int]) -> int:
    result, array_sum = -sys.maxsize, 0
    for n in nums:
      array_sum = max(n, array_sum + n)
      result = max(result, array_sum)
    
    return result
