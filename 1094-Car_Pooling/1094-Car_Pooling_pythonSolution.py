class Solution:
  def carPooling(self, trips: List[List[int]], capacity: int) -> bool:
    changes = {}
    for trip in trips:
      if not changes.get(trip[1]):
        changes[trip[1]] = 0
      if not changes.get(trip[2]):
        changes[trip[2]] = 0
      changes[trip[1]] += trip[0]
      changes[trip[2]] -= trip[0]
    
    n_passengers = 0
    for stop in sorted(changes):
      n_passengers += changes[stop]
      if n_passengers > capacity:
        return False
    return True
