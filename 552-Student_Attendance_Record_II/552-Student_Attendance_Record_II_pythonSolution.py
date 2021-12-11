class Solution:
  def checkRecord(self, n: int) -> int:
    MOD = 1000000007;
    a0l0, a0l1, a0l2, a1l0, a1l1, a1l2 = 1, 0, 0, 0, 0, 0;
    for i in range(n + 1):
      new_a0l0 = (a0l0 + a0l1 + a0l2) % MOD;
      new_a1l0 = (new_a0l0 + a1l0 + a1l1 + a1l2) % MOD;
      a0l2 = a0l1;
      a0l1 = a0l0;
      a0l0 = new_a0l0;
      a1l2 = a1l1;
      a1l1 = a1l0;
      a1l0 = new_a1l0;
    return a1l0;
