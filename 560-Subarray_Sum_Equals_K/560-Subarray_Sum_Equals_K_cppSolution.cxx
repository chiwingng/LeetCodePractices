class Solution {
public:
  int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> sum_counts;
    int curr = 0;
    int count = 0;
    sum_counts[0] = 1;
    for (const int& n : nums) {
      curr += n;
      count += sum_counts[curr - k];
      sum_counts[curr]++;
    }
    return count;
  }
};
