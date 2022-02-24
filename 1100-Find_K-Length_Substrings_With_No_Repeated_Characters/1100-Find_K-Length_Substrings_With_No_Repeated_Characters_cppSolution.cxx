class Solution {
public:
  int numKLenSubstrNoRepeats(string s, int k) {
    // obviously invalid cases
    if (k > s.size() || k > 26) return 0;
    // hash map of character locations
    unordered_map<char, int> char_locs;
    int result = 0, start = 0;
    for (int end = 0; end < s.size();) {
      // move start to the next location of last found s[end] character, and unregister all characters along the way
      for (; start < char_locs[s[end]]; start++) char_locs[start] = 0;
      // register the current chracter. +1 is used to distinguish from the default initialized 0 values in the hashmap.
      char_locs[s[end]] = end + 1;
      // increment end here to avoid duplicated addition
      end++;
      // if not incremented above, here would be end - start + 1 == k
      // check if the number of characters between start and end is k
      // if yes we found a valid substring, increment result
      // move start forward and unregister the corresponding characterX
      if (end - start == k) {
        result++;
        char_locs[s[start++]] = 0;
      }
    }
    return result;
  }
};
