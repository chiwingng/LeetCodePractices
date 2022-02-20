class Solution:
  def subarraySum(self, nums: List[int], k: int) -> int:
    # Counter is also OK to use in this case, though a bit slower
    counts = defaultdict(int)
    counts[0] = 1
    prefix, result = 0, 0
    for n in nums:
      prefix += n
      result += counts[prefix - k]
      counts[prefix] += 1
    return result
