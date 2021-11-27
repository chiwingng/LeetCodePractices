#include <vector>
#include <algorithm> // std::max

class Solution {
public:
  int maxSubArray(std::vector<int>& nums) {
    int result = INT_MIN, sum = 0;
      for (const int& n : nums) {
        sum = max(n, sum + n);
        result = std::max(result, sum);
      }
    return result;
  }
};
