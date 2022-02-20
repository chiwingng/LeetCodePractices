class Solution_bitmask {
public:
  vector<vector<int>> subsets(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> power_set;
    int n_subsets = 1 << n;
    for (int i = 0; i < n_subsets; i++) {
      vector<int> subset;
      for (int j = 0; j < n; j++) {
        if ((i >> j) & 1) subset.push_back(nums[j]);
      }
      power_set.push_back(subset);
    }
    return power_set;
  }
};

class Solution_iterative {
public:
  vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> power_set = {{}};
    for (const int& n : nums) {
      int n_sets = power_set.size();
      for (int i = 0; i < n_sets; i++) {
        power_set.push_back(power_set[i]);
        power_set.back().push_back(n);
      }
    }
    return power_set;
  }
};

class Solution_backtrack {
  void buildSubSets(const vector<int>& nums, vector<int>& subset, vector<vector<int>>& power_set, int i) {
    power_set.push_back(subset);
    for (int j = i; j < nums.size(); j++) {
      subset.push_back(nums[j]);
      buildSubSets(nums, subset, power_set, j+1);
      subset.pop_back();
    }
  }
public:
  vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> power_set;
    vector<int> subset;
    buildSubSets(nums, subset, power_set, 0);
    return power_set;
  }
};
