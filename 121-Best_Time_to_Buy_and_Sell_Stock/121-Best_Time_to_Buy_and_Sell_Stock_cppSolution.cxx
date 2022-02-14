#include <vector>

class Solution {
public:
  int maxProfit(vector<int>& prices) {
    int cost = INT_MAX, max_profit = 0;
    for (const int& p : prices) {
      if (p < cost) cost = p;
      else max_profit = max(max_profit, p - cost);
    }
    return max_profit;
  }
};
