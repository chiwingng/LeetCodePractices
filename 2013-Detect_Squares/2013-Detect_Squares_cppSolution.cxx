#include <vector>
#include <unordered_set>
#include <unordered_map>

class DetectSquares {
  vector<vector<int>> counts;
  unordered_map<int, unordered_set<int>> diffToX, sumToX;
  
public:
  DetectSquares() {
    counts = vector<vector<int>>(1001, vector<int>(1001, 0));
  }
    
  void add(vector<int> point) {
    int x = point[0], y = point[1];
    counts[x][y]++;
    diffToX[y-x].insert(x);
    sumToX[y+x].insert(x);
  }
    
  int count(vector<int> point) {
    int result = 0;
    int x = point[0], y = point[1];
    for (const int& x1 : diffToX[y-x]) {
      if (x == x1) continue;
      int y1 = y - x + x1;
      result += counts[x1][y] * counts[x][y1] * counts[x1][y1];
    }
    for (const int& x1 : sumToX[y+x]) {
      if (x == x1) continue;
      int y1 = y + x - x1;
      result += counts[x1][y] * counts[x][y1] * counts[x1][y1];
    }
    return result;
  }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */
