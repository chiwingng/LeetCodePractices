/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *  public:
 *   int get(int row, int col);
 *   vector<int> dimensions();
 * };
 */

class Solution {
public:
  int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
    vector<int> matdims = binaryMatrix.dimensions();
    int n_rows = matdims[0], n_cols = matdims[1];
    
    int curr_row = 0, curr_col = n_cols - 1;
    while(curr_row < n_rows && curr_col >= 0) {
      // search for the next row with curr_col is 1
      while(curr_row < n_rows && binaryMatrix.get(curr_row, curr_col) == 0)
        curr_row++;
      
      // if we have curr_row still in range, perform binary search for the first 1
      if (curr_row < n_rows) {
        int left = 0, right = curr_col;
        while(left <= right) {
          // running again on left == right ensures left is incremented if we landed on the last 0
          int mid = (left + right) / 2;
          if (binaryMatrix.get(curr_row, mid) == 0)
            left = mid + 1; // the first 1 must be on the right side
          else right = mid - 1; // the first 1 must be either mid or on the left side
        }
        curr_col = left;
      }
      else if (curr_col == n_cols - 1) curr_col = -1; // edge case of all zeros
      curr_row++;
    }
    return curr_col;
  }
};
