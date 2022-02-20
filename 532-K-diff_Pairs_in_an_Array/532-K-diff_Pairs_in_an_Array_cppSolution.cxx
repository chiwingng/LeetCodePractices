class Solution_hashmap {
public:
  int findPairs(vector<int>& nums, int k) {
    int result = 0;
    if (k == 0) {
      unordered_map<int, int> counts;
      for (const int& n : nums)
        if (++counts[n] == 2) result++; // we have a 0-diff pair!
    }
    else {
      unordered_set<int> unique_nums(nums.begin(), nums.end());
      for (const int& n : unique_nums) {
        result += unique_nums.count(n - k); // or n+k, they are equivalent
      }
    }
    return result;
  }
};

class Solution_2ptrs {
public:
  int findPairs(vector<int>& nums, int k) {
    int result = 0;
    sort(nums.begin(), nums.end());
    int left = 0, right = 1, n = nums.size();
    while (left < n && right < n) {
      if (left == right || nums[right] - nums[left] < k) right++;
      else if (nums[right] - nums[left] > k) left++;
      else {
        result++; left++;
        while (left < n && nums[left] == nums[left - 1]) left++;
      }
    }
    return result;
  }
};
