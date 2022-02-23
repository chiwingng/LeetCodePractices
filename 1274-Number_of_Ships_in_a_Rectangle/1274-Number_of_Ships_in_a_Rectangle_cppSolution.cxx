/**
 * // This is Sea's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Sea {
 *   public:
 *     bool hasShips(vector<int> topRight, vector<int> bottomLeft);
 * };
 */

class Solution {
public:
  int countShips(Sea sea, vector<int> topRight, vector<int> bottomLeft) {
    // if the current rectangle is not valid, return 0
    if (bottomLeft[0] > topRight[0] || bottomLeft[1] > topRight[1])
      return 0;
    // if no ship, return 0
    if (!sea.hasShips(topRight, bottomLeft)) return 0;
    
    // it has a ship and is a single point, return 1
    if (topRight == bottomLeft) return 1;
    
    // not a single point, break the rectangle down to 4 sub-rectangles
    int midX = (topRight[0] + bottomLeft[0])/2;
    int midY = (topRight[1] + bottomLeft[1])/2;
    
    return countShips(sea, {midX, midY}, bottomLeft) +
           countShips(sea, {midX, topRight[1]}, {bottomLeft[0], midY+1}) +
           countShips(sea, {topRight[0], midY}, {midX+1, bottomLeft[1]}) +
           countShips(sea, topRight, {midX+1, midY+1});
  }
};
