class Solution {
public:
  int calculateMinimumHP(vector<vector<int>>& dungeon) {
    int n_rows = dungeon.size(), n_cols = dungeon[0].size();
    vector<vector<int>> dp(n_rows+1, vector<int>(n_cols+1, INT_MAX));
    
    dp[n_rows][n_cols - 1] = 1;
    dp[n_rows - 1][n_cols] = 1;
    
    for (int r = n_rows - 1; r >= 0; r--) {
      for (int c = n_cols - 1; c >= 0; c--) {
        dp[r][c] = max(1, min(dp[r][c+1], dp[r+1][c]) - dungeon[r][c]);
      }
    }
    return dp[0][0];
  }
};
