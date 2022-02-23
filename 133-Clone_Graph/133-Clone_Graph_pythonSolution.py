"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

class Solution:
  oldToNew = {}
  def cloneGraph(self, node: 'Node') -> 'Node':
    if not node:
      return node
    newNode = self.oldToNew.get(node)
    if newNode:
      return newNode
    else:
      newNode = Node(node.val)
      self.oldToNew[node] = newNode
      for n in node.neighbors:
        self.oldToNew[node].neighbors.append(self.cloneGraph(n))
      return self.oldToNew[node]
    
