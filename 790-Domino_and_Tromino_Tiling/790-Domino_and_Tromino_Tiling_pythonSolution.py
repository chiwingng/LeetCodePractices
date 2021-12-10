class Solution:
  def numTilings(self, n: int) -> int:
    MOD = 1000000007
    if n < 3:
      return n
    fcurr = 5
    fprev = 2
    fbp = 1
    for k in range(4, n+1):
      temp = fprev
      fprev = fcurr
      fcurr = ((fcurr << 1) + fbp) % MOD
      fbp = temp
    return fcurr
