class DetectSquares:

  def __init__(self):
    self.counts = Counter()
    

  def add(self, point: List[int]) -> None:
    self.counts[tuple(point)] += 1

  def count(self, point: List[int]) -> int:
    result = 0
    x, y = point
    for (x1, y1), cnt in self.counts.items():
      if x != x1 and abs(x - x1) == abs(y - y1):
        result += cnt * self.counts[(x, y1)] * self.counts[(x1, y)]
    return result


# Your DetectSquares object will be instantiated and called as such:
# obj = DetectSquares()
# obj.add(point)
# param_2 = obj.count(point)
