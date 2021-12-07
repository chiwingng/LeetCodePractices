# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
  def nodeHeight(self, node: Optional[TreeNode], result: List[List[int]]) -> int:
    if not node:
      return -1
    curr_height = max(self.nodeHeight(node.left, result), self.nodeHeight(node.right, result)) + 1
    if curr_height == len(result):
      result.append([])
    result[curr_height].append(node.val)
    return curr_height
  def findLeaves(self, root: Optional[TreeNode]) -> List[List[int]]:
    result = []
    self.nodeHeight(root, result)
    return result
