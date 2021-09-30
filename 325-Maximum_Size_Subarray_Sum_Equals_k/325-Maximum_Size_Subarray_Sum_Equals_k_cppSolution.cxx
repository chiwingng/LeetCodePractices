class Solution {
public:
  int maxSubArrayLen(vector<int>& nums, int k) {
    unordered_map<int, int> sum_indices;
    int prefix_sum = 0, n = nums.size(), result = 0;
    sum_indices.insert({0,-1});
    for (int i = 0; i < n; i++) {
      prefix_sum += nums[i];
      if (sum_indices.find(prefix_sum) == sum_indices.end())
        sum_indices[prefix_sum] = i;
      auto it = sum_indices.find(prefix_sum - k);
      if (it != sum_indices.end()) {
        result = max(result, i - it->second);
      }
    }
    return result;
  }
};
