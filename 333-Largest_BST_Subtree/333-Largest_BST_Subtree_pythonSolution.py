# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
  # class holding BST information
  class nodeInfo:
    def __init__(self, valid=True, min_v=sys.maxsize, max_v=-sys.maxsize-1, max_size=0):
      self.valid = valid
      self.min_v = min_v
      self.max_v = max_v
      self.max_size = max_size

  # function to compute BST validness based on subtree info
  def computeNodeInfo(self, node: Optional[TreeNode]) -> nodeInfo:
    # base case: null node is a valid BST with size 0
    # min_v and max_v are initialized to ensure parent node is treated as valid BST
    if not node:
      return self.nodeInfo()

    # compute BST info for children
    left_info = self.computeNodeInfo(node.left)
    right_info = self.computeNodeInfo(node.right)

    # BST validness:
    # left subtree and right subtree should both be valid BSTs
    # node value should be in between max of left subtree and min of right subtree
    # if it is not a valid BST, max_size should be the max of BST sizes from left and right children
    if not left_info.valid or not right_info.valid or node.val >= right_info.min_v or node.val <= left_info.max_v:
      return self.nodeInfo(False, -sys.maxsize-1, sys.maxsize, max(left_info.max_size, right_info.max_size))

    # compute the new min/max value based on children values
    # need also to consider null children cases
    min_value = min(left_info.min_v, node.val)
    max_value = max(right_info.max_v, node.val)

    # This node is a valid BST, count all nodes under it plus itself in max_size
    return self.nodeInfo(True, min_value, max_value, left_info.max_size + right_info.max_size + 1)

  # function to determine the largest BST under the root node
  def largestBSTSubtree(self, root: Optional[TreeNode]) -> int:
    # simply the max_size of nodeInfo of root
    return self.computeNodeInfo(root).max_size;
