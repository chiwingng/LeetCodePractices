# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
  def findTilt(self, root: Optional[TreeNode]) -> int:
    tilt = 0
    
    def getSum(node: Optional[TreeNode]) ->int:
      nonlocal tilt
      
      if not node:
        return 0
      l = getSum(node.left)
      r = getSum(node.right)
      
      tilt += abs(l - r)
      return node.val + l + r
    
    getSum(root)
    return tilt
