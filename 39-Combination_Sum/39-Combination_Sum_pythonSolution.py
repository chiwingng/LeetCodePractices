class Solution:
  def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
    result = []
    
    def backtrack(remain: int, comb: List[int], curr: int):
      if remain == 0:
        # deep copy of comb, otherwise will become empty lists
        result.append(list(comb))
        return
      elif remain < 0:
          # exceeded target
        return
      
      for i in range(curr, len(candidates)):
        # add current number into comb
        comb.append(candidates[i])
        # allow duplication of numbers, rather than going directly to i+1
        backtrack(remain - candidates[i], comb, i)
        # backtrack, pop the number from comb
        comb.pop()
    
    backtrack(target, [], 0)
    
    return result
