class Solution(object):
  def maxSubArrayLen(self, nums, k):
    """
    :type nums: List[int]
    :type k: int
    :rtype: int
    """
    sum_indices = {0 : -1}
    prefix_sum, result = 0, 0
    for i in range(len(nums)):
      prefix_sum += nums[i]
      # find the index of needed sum
      if prefix_sum - k in sum_indices:
        result = max(result, i - sum_indices[prefix_sum - k])
      if prefix_sum not in sum_indices:
        sum_indices[prefix_sum] = i
    
    return result
