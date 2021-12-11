class Solution {
  // function to find the GCD of two numbers
  int gcd(int a, int b) {
    while (a > 0) {
      int temp = a;
      a = b % a;
      b = temp;
    }
    return b;
  }
public:
  int nthMagicalNumber(int n, int a, int b) {
    const int MOD = 1e9 + 7;
    // binary search, lowest possible should be the minimum of two numbers
    // largest possible should be the nth multiple of the min
    long low = min(a, b), high = low * n;
    // compute the least common multiple of the two numbers
    int lcm = a / gcd(a, b) * b;
    while (low < high) {
      long mid = (low + high) / 2;
      // number of magical numbers up to mid is mid/a + mid/b - mid/lcm
      if (mid/a + mid/b - mid/lcm < n) low = mid + 1;
      else high = mid;
    }
    // return the residue of low divided by our favorite 1e9 + 7
    return int(low % MOD);
  }
};
