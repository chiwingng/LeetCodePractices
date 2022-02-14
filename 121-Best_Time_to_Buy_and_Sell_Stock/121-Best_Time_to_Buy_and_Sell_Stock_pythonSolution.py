class Solution:
  def maxProfit(self, prices: List[int]) -> int:
    cost = sys.maxsize
    profit = 0
    for sell in prices:
      if sell < cost:
        cost = sell
      else:
        profit = max(profit, sell - cost)
    return profit
