class Solution:
  def numberOfArithmeticSlices(self, nums: List[int]) -> int:
    if len(nums) < 3:
      return 0
    length, result, diff = 1, 0, nums[1] - nums[0]
    for i in range(2, len(nums)):
      newdiff = nums[i] - nums[i-1]
      if newdiff != diff:
        result += (length*(length-1))//2
        diff = newdiff
        length = 1
      else:
        length += 1
    
    return result + ((length*(length-1))//2)
