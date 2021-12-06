# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
  def rob_helper(self, node: Optional[TreeNode]):
    if not node:
      return [0, 0]
    left_results = self.rob_helper(node.left)
    right_results = self.rob_helper(node.right)
    rob_result = node.val + left_results[1] + right_results[1]
    not_rob = left_results[0] + right_results[0]
    return [max(rob_result, not_rob), not_rob]
  
  def rob(self, root: Optional[TreeNode]) -> int:  
    return self.rob_helper(root)[0]
