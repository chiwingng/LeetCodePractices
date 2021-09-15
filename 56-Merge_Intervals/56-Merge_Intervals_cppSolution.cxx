class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> merged = {intervals[0]};
    int n_intervals = intervals.size();
    for (int i = 1; i < n_intervals; i++) {
      int currentEndTime = merged.back().at(1);
      if (currentEndTime < intervals[i][0])
        merged.push_back(intervals[i]);
      else
        merged.back().at(1) = max(currentEndTime, intervals[i][1]);
    }
    return merged;
  }
};
