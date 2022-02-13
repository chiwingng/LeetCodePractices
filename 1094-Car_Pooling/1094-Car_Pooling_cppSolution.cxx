#include <vector>
#include <map>

class Solution {
public:
  bool carPooling(vector<vector<int>>& trips, int capacity) {
    // keep track of passengers getting on/off
    map<int, int> changes;
    for (const vector<int>& trip : trips) {
      changes[trip[1]] += trip[0];
      changes[trip[2]] -= trip[0];
    }
    int n_pass = 0;
    // simulate the passengers getting on/off at each stop
    for (auto it : changes) {
      n_pass += it.second;
      // false if capacity exceeded
      if (n_pass > capacity) return false;
    }
    // dropped off the final passenger, job done!
    return true;
  }
};
