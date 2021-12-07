class SnapshotArray:
  
  def __init__(self, length: int):
    self.snaps = [[[-1, 0]] for _ in range(length)]
    self.curr_snap = 0

  def set(self, index: int, val: int) -> None:
    self.snaps[index].append([self.curr_snap, val])

  def snap(self) -> int:
    self.curr_snap += 1
    return self.curr_snap - 1

  def get(self, index: int, snap_id: int) -> int:
    i = bisect.bisect(self.snaps[index], [snap_id+1, 0]) - 1
    return self.snaps[index][i][1]


# Your SnapshotArray object will be instantiated and called as such:
# obj = SnapshotArray(length)
# obj.set(index,val)
# param_2 = obj.snap()
# param_3 = obj.get(index,snap_id)
