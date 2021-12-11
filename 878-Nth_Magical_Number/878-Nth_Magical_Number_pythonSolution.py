class Solution:
  def gcd(x: int, y: int) -> int:
    while y > 0:
      x, y = y, x%y
    return x
  
  def nthMagicalNumber(self, n: int, a: int, b: int) -> int:
    MOD = 1000000007
    low = min(a, b)
    high = low * n
    lcm = a / gcd(a, b) * b
    while low < high:
      mid = (low + high) // 2
      if mid // a + mid // b - mid // lcm < n:
        low = mid + 1
      else:
        high = mid
    
    return low % MOD
