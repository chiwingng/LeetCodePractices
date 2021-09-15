class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> index;
    int start = 0, end = 0, result = 0;
    for (char& c : s) {
      // check if c is in index and if prev_index is after start
      auto it = index.find(c);
      if (it != index.end() && it->second >= start) {
        // update result
        result = max(result, end - start);
        // move start
        start = it->second + 1;
      }
      // register index and increment end
      index[c] = end++;
    }
    return max(result, end - start);
  }
};
