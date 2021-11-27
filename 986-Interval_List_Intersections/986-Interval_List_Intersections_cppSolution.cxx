#include <vector>
#include <algorithm> // std::max

class Solution {
public:
  std::vector<std::vector<int> > intervalIntersection(const std::vector<std::vector<int> >& firstList, const std::vector<std::vector<int> >& secondList) {
    std::vector<std::vector<int> > result;
    int p1 = 0, p2 = 0;
    int n1 = firstList.size(), n2 = secondList.size();
        
    while (p1 < n1 && p2 < n2) {
      int low = std::max(firstList[p1][0], secondList[p2][0]);
      int high = std::min(firstList[p1][1], secondList[p2][1]);
      if (low <= high) result.push_back({low, high});
      if (high == secondList[p2][1]) p2++;
      else p1++;
    }
        
    return result;
  }
};
