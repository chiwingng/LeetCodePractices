# """
# This is BinaryMatrix's API interface.
# You should not implement it, or speculate about its implementation
# """
#class BinaryMatrix(object):
#  def get(self, row: int, col: int) -> int:
#  def dimensions(self) -> list[]:

class Solution:
  def leftMostColumnWithOne(self, binaryMatrix: 'BinaryMatrix') -> int:
    n_rows, n_cols = binaryMatrix.dimensions()
    
    curr_row, curr_col = 0, n_cols - 1
    while curr_row < n_rows and curr_col >= 0:
      # find the next row with the current col nonzero
      while curr_row < n_rows and binaryMatrix.get(curr_row, curr_col) == 0:
        curr_row += 1
      # the edge case: everything 0
      if curr_row == n_rows:
        if curr_col == n_cols - 1:
          return -1
      else:
        # binary search
        left, right = 0, curr_col
        while left <= right:
          mid = (left + right) // 2
          if binaryMatrix.get(curr_row, mid) == 0:
            left = mid + 1
          else:
            right = mid - 1
        curr_col = left
      # move to next row
      curr_row += 1

    return curr_col
