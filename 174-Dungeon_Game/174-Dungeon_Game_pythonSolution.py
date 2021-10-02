class Solution(object):
  def calculateMinimumHP(self, dungeon):
    """
    :type dungeon: List[List[int]]
    :rtype: int
    """
    n_rows, n_cols = len(dungeon), len(dungeon[0])
    dp = [[1e7] * (n_cols+1) for _ in range(n_rows+1)]
    # base cases
    dp[n_rows][n_cols-1] = dp[n_rows-1][n_cols] = 1
    
    for r in range(n_rows-1, -1, -1):
      for c in range(n_cols-1, -1, -1):
        dp[r][c] = max(1, min(dp[r+1][c], dp[r][c+1]) - dungeon[r][c])
        
    return dp[0][0]
