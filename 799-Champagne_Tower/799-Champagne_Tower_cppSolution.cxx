#include <vector>
#include <algorithm> // std::min

class Solution {
public:
  double champagneTower(int poured, int query_row, int query_glass) {
    // In the final row we have query_row + 1 glasses
    std::vector<double> dp(query_row + 1, 0);
    // Initially all poured glasses of champagne are in the 0th glass
    // we align all glasses in each row to the left
    // so each glass has its excess wine flows to the glass
    // directly below it and the lower right glass.
    
    // G
    // |\
    // G G
    // |\|\
    // G G G
    // ...
    
    dp[0] = poured;
    for (int row = 0; row < query_row; row++) {
      // after flowing through each row
      // we work from the right side as it would be simpler
      for (int col = row; col >= 0; col--) {
        // one glass of champagne is left in the glass in previous row
        if (--dp[col] > 0) {
          // then we have half of the champagne left in the same column
          dp[col] /= 2.;
          // the rest flows to the next column in the row
          dp[col+1] += dp[col];
        }
        // if we have no champagne flowing to this row, set it to 0.
        else dp[col] = 0;
      }
    }
    // if we have more than 1 glass flowing through, this glass is full (max. 1)
    return std::min(1., dp[query_glass]);
  }
};
