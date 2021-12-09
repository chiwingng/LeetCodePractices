class Solution:
  def canReach(self, arr: List[int], start: int) -> bool:
    n = len(arr)
    bfs_queue = [start]
    while bfs_queue:
      curr = bfs_queue.pop(0)
      # done when we reach 0
      if arr[curr] == 0:
        return True
      # skip visited nodes
      if arr[curr] < 0:
        continue
      
      # available next nodes
      for next_i in [curr - arr[curr], curr + arr[curr]]:
        if 0 <= next_i < n:
          bfs_queue.append(next_i)

      # mark as visited
      arr[curr] = -arr[curr]
      
    return False
