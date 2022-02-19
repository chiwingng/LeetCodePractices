# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
  def findNearestRightNode(self, root: TreeNode, u: TreeNode) -> Optional[TreeNode]:
    q = deque([root])
    found_u = False
    
    while q:
      for i in range (len(q)):
        node = q.popleft()
        if found_u:
          return node
        if node == u:
          found_u = True
        else:
          if node.left:
            q.append(node.left)
          if node.right:
            q.append(node.right)
      if found_u:
        return None
    return None
