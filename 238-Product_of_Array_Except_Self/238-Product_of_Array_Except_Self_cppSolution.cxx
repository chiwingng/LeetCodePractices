#include <vector>

class Solution {
public:
  std::vector<int> productExceptSelf(std::vector<int>& nums) {
    std::vector<int> result(nums.size(), 1);
    int n = nums.size();
    // compute left suffix
    for (int i = 1; i < n; i++) {
      result[i] = result[i-1] * nums[i-1];
    }
    // multiply with right suffix
    int right_suffix = 1;
    for (int i = n-2; i >= 0; i--) {
      right_suffix *= nums[i+1];
      result[i] *= right_suffix;
    }
    return result;
  }
};
