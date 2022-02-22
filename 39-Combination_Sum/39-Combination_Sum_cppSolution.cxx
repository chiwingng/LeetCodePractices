class Solution {
  void backtrack(vector<vector<int>>& result, const vector<int>& candidates, vector<int>& list, int curr, int remain) {
    if (remain == 0) {
      result.push_back(list);
      return;
    }
    if (remain < 0) return;
    for (int i = curr; i < candidates.size(); i++) {
      list.push_back(candidates[i]);
      backtrack(result, candidates, list, i, remain - candidates[i]);
      list.pop_back();
    }
  }
public:
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> result;
    vector<int> list;
    backtrack(result, candidates, list, 0, target);
    return result;
  }
};
