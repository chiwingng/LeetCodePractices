class Solution(object):
  def longestCommonSubsequence(self, text1, text2):
    """
    :type text1: str
    :type text2: str
    :rtype: int
    """
    dp = [0] * (len(text2)+1)
    
    for i1 in range(len(text1)-1, -1, -1):
      newdp = [0] * (len(text2)+1)
      for i2 in range(len(text2)-1, -1, -1):
        if text1[i1] == text2[i2]:
          newdp[i2] = dp[i2+1] + 1
        else:
          newdp[i2] = max(dp[i2], newdp[i2+1])
      dp = newdp
    
    return dp[0]
