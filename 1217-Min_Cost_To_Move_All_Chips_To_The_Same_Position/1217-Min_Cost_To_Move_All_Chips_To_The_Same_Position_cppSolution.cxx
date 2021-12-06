class Solution {
public:
  int minCostToMoveChips(vector<int>& position) {
    // count chips at odd and even positions
    // since chips can move without cost between positions with the same parity
    // we can gather all chips at two neighboring sites
    // and then move the chips at the site with less chips to minimize the cost
    vector<int> sum(2, 0);
    for (const int& p : position) sum[p % 2]++;
    return min(sum[0], sum[1]);
  }
};
