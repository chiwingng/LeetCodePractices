class Solution:
  def allPathsSourceTarget(self, graph: List[List[int]]) -> List[List[int]]:
    target = len(graph) - 1
    allPaths = []
    
    # dfs helper function
    def pathHelper(node, path):
      # reached target, dfs reached endpoint
      if node == target:
        allPaths.append(list(path))
        return
      # continue with the neighbors of current node
      for nextNode in graph[node]:
        path.append(nextNode)
        pathHelper(nextNode, path)
        path.pop()
    # start the dfs with source node 0
    path = deque([0])
    pathHelper(0, path)
    
    return allPaths
