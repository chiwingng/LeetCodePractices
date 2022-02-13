#include <vector>

class Solution {
public:
  bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    // we have no flowers to plant, easy.
    if (n == 0) return true;
    int slots = flowerbed.size();
    for (int i = 0; i < slots; i++) {
      // the slot is already occupied
      if (flowerbed[i]) continue;
      // the left slot is already occupied
      if (i > 0 && flowerbed[i-1]) continue;
      // the right slot is already occupied
      if (i < slots - 1 && flowerbed[i+1]) continue;
      // now we can plant the flower
      flowerbed[i] = 1;
      // we are done if no more flowers need to be planted
      if (--n == 0) return true;
    }
    // we have flowers left after going through the whole flowerbed. Job is not possible.
    return false;
  }
};
