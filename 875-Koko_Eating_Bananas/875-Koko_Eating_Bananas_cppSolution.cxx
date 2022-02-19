class Solution {
public:
  int minEatingSpeed(vector<int>& piles, int h) {
    int min_k = 1, max_k = *max_element(piles.begin(), piles.end());

    // binary search between 1 and max bananas in the piles
    // eating faster than the max pile is not meaningful
    while (max_k > min_k) {
      int mid_k = (max_k + min_k) >> 1;
      
      int hours = 0;
      for (const int& p : piles) hours += (p + mid_k - 1)/mid_k;
      if (hours > h) min_k = mid_k + 1; // mid_k is not enough, we need at least mid_k + 1
      else max_k = mid_k; // mid_k is enough, so it is the max.
    }
    
    return min_k;
  }
};
