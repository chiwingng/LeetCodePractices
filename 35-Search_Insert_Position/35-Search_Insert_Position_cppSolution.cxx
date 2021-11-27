#include <vector>
#include <algorithm> // std::lower_bound

class Solution {
public:
  int searchInsert(std::vector<int>& nums, int target) {
    if (target <= nums[0]) return 0;
    if (target > nums.back()) return nums.size();
    int low = 0, high = nums.size() - 1;
    while (low < high) {
      int mid = (low + high) / 2;
      if (nums[mid] < target) low = mid + 1;
      else high = mid;
    }
    return low;
  }
};

class Alternative_Solution {
public:
  int searchInsert(std::vector<int>& nums, int target) {
    return std::lower_bound(nums.begin(), nums.end(), target) - nums.begin();
  }
};
