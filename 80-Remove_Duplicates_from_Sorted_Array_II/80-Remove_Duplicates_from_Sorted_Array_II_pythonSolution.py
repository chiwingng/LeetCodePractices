class Solution:
  def removeDuplicates(self, nums: List[int]) -> int:
    loc, val, count = 1, nums[0], 1
    
    for n in nums[1:]:
      if n == val:
        count += 1
      else:
        val = n
        count = 1
      
      if count <= 2:
        nums[loc] = val
        loc += 1
      
    return loc
