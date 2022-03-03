class Solution {
public:
  string removeKdigits(string num, int k) {
    if (num.size() <= k) return "0";
    string result;
    for (const char& c : num) {
      while (!result.empty() && k > 0 && c < result.back()) {
        result.pop_back();
        k--;
      }
      result.push_back(c);
    }
    int idx = 0;
    while (idx < result.size() && result[idx] == '0') idx++;
    if (idx + k >= result.size()) return "0";
    else return result.substr(idx, result.size() - k - idx);
  }
};
