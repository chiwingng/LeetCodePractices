class Solution {
public:
  int longestCommonSubsequence(string text1, string text2) {
    int length1 = text1.size(), length2 = text2.size();
    vector<int> dp(length2 + 1, 0);
    for (int i1 = length1 - 1; i1 >= 0; i1--) {
      vector<int> newdp(length2 + 1, 0);
      for (int i2 = length2 - 1; i2 >= 0; i2--) {
        if (text1[i1] == text2[i2]) newdp[i2] = dp[i2+1] + 1;
        else newdp[i2] = max(newdp[i2+1], dp[i2]);
      }
      dp = newdp;
    }
    return dp[0];
  }
};
