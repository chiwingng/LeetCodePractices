class Solution {
public:
  int checkRecord(int n) {
    const long MOD = 1000000007;
    // these six numbers counts the number (axly) of possible attendance records with x A's and y ending L's
    long a0l0 = 1, a0l1 = 0, a0l2 = 0, a1l0 = 0, a1l1 = 0, a1l2 = 0;
    for (int i = 0; i <= n; i++) {
      // a0l0 state can be reached by appending a P to any of the 0 A states
      long new_a0l0 = (a0l0 + a0l1 + a0l2) % MOD;
      // a1l0 state can be reached by appending an A to any of the 0A states or a P to any of the 1A states
      // it is essentially the total number of states in the previous step
      long new_a1l0 = (new_a0l0 + a1l0 + a1l1 + a1l2) % MOD;
      // all the rest states are reached by appending an L to another state:
      a0l2 = a0l1;
      a0l1 = a0l0;
      a0l0 = new_a0l0;
      a1l2 = a1l1;
      a1l1 = a1l0;
      a1l0 = new_a1l0;
    }
    // we need the total number of states of length n, so we run one more step and take a1l0 as our answer
    return int(a1l0);
  }
};
