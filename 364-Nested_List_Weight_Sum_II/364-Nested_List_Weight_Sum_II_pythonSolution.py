# """
# This is the interface that allows for creating nested lists.
# You should not implement it, or speculate about its implementation
# """
#class NestedInteger:
#    def __init__(self, value=None):
#        """
#        If value is not specified, initializes an empty list.
#        Otherwise initializes a single integer equal to value.
#        """
#
#    def isInteger(self):
#        """
#        @return True if this NestedInteger holds a single integer, rather than a nested list.
#        :rtype bool
#        """
#
#    def add(self, elem):
#        """
#        Set this NestedInteger to hold a nested list and adds a nested integer elem to it.
#        :rtype void
#        """
#
#    def setInteger(self, value):
#        """
#        Set this NestedInteger to hold a single integer equal to value.
#        :rtype void
#        """
#
#    def getInteger(self):
#        """
#        @return the single integer that this NestedInteger holds, if it holds a single integer
#        Return None if this NestedInteger holds a nested list
#        :rtype int
#        """
#
#    def getList(self):
#        """
#        @return the nested list that this NestedInteger holds, if it holds a nested list
#        Return None if this NestedInteger holds a single integer
#        :rtype List[NestedInteger]
#        """

class Solution:
  
  def weightedSum(self, ni: NestedInteger, curr_depth: int) -> int:
    self.max_depth = max(self.max_depth, curr_depth)
    if ni.isInteger():
      self.total_sum += ni.getInteger()
      return curr_depth * ni.getInteger()
    else:
      weighted_sum = 0
      for nestedni in ni.getList():
        weighted_sum += self.weightedSum(nestedni, curr_depth + 1)
      return weighted_sum
    
  def depthSumInverse(self, nestedList: List[NestedInteger]) -> int:
    self.total_sum, self.max_depth, result = 0, 1, 0
    
    for ni in nestedList:
      result -= self.weightedSum(ni, 1)
    
    return result + (self.max_depth + 1) * self.total_sum
