class Solution {
public:
  int numTilings(int n) {
    const int MOD = 1e9 + 7;
    if (n < 3) return n;
    
    long fcurr = 5, fprev = 2, fbp = 1;
    for (int k = 4; k <= n; k++) {
      long temp = fprev;
      fprev = fcurr;
      fcurr = ((fcurr << 1) + fbp) % MOD; // f(k) = 2 * f(k-1) + f(k-3)
      fbp = temp;
    }
    return static_cast<int>(fcurr);
  }
};
