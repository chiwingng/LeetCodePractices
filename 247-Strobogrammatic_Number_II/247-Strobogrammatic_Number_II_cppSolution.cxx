#include <vector>
#include <string>
#include <unordered_map>

class Solution {
  vector<char> self_match;
  unordered_map<char, char> char_map;
public:
  vector<string> findStrobogrammatic(int n) {
    self_match = {'0', '1', '8'};
    char_map = {{'0', '0'}, {'1', '1'}, {'6', '9'}, {'8', '8'}, {'9', '6'}};
    string curr(n, ',');
    vector<string> result;
    backtrack(curr, 0, n-1, result);
    return result;
  }
  void backtrack(string& curr, int left, int right, vector<string>& result) {
    if (left > right) result.push_back(curr);
    else if (left == right) {
      for (const char &c : self_match) {
        curr[left] = c;
        result.push_back(curr);
      }
    }
    else {
      for (auto& [lc, rc] : char_map) {
        if (lc == '0' && left == 0) continue;
        curr[left] = lc;
        curr[right] = rc;
        backtrack(curr, left+1, right-1, result);
      }
    }
  }
};
