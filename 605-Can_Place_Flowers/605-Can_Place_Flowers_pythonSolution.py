class Solution:
  def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
    if n == 0:
      # we can always plant 0 flowers
      return True
    
    n_slots = len(flowerbed)
    
    for i in range(0, n_slots):
      if flowerbed[i] == 1:
        # flower is already planted
        continue
      if i > 0 and flowerbed[i-1] == 1:
        # flower is already planted in the left slot
        continue
      if i < n_slots - 1 and flowerbed[i+1] == 1:
        # flower is already planted in the right slot
        continue
      # no-adjacent-flowers rule is fulfilled. Now plant the flower happily
      flowerbed[i] = 1
      # decrement the total number of flowers to plant
      n -= 1
      if n == 0:
        # if we have no more flowers to plant, we are done
        return True
    # we end up here with flowers left to plant, so the job is impossible.
    return False
