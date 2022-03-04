class Solution:
  def champagneTower(self, poured: int, query_row: int, query_glass: int) -> float:
    dp = [0.0] * (query_row + 1)
    dp[0] = poured
    for r in range(query_row):
      for c in range(r, -1, -1):
        dp[c] = max((dp[c] - 1)/2, 0)
        dp[c+1] += dp[c]
    return min(dp[query_glass], 1)
