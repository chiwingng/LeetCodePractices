#include <vector>
#include <string>
#include <unordered_map>

class Solution {
public:
  vector<int> findAnagrams(string s, string p) {
    unordered_map<char, int> counts;
    vector<int> result;
    if (p.size() > s.size()) return result;
    
    for (const char& c : p) counts[c]++;
    int length = p.size();
    
    for (int i = 0; i < length; i++) {
      if (--counts[s[i]] == 0) counts.erase(s[i]);
    }
    if (counts.empty()) result.push_back(0);
    
    for (int i = length; i < s.size(); i++) {
      if (--counts[s[i]] == 0) counts.erase(s[i]);
      if (++counts[s[i - length]] == 0) counts.erase(s[i - length]);
      if (counts.empty()) result.push_back(i - length + 1);
    }
    
    return result;
  }
};
