class Solution:
  def searchInsert(self, nums: List[int], target: int) -> int:
    low, high = 0, len(nums)
    while low < high:
      mid = (low + high) // 2
      if nums[mid] == target:
        return mid
      if nums[mid] < target:
        low = mid + 1
      else:
        high = mid
    return low

import bisect

class Alternative_Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        return bisect.bisect_left(nums, target)
