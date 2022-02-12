class Solution_1 {
public:
  char findTheDifference(string s, string t) {
    int sum = 0;
    for (const char& c : t) sum ^= c;
    for (const char& c : s) sum ^= c;
    return (char) sum;
  }
};

class Solution_2 {
public:
  char findTheDifference(string s, string t) {
    int sum = 0;
    for (const char& c : t) sum += c;
    for (const char& c : s) sum -= c;
    return (char) sum;
  }
};

class Solution_3 {
public:
  char findTheDifference(string s, string t) {
    vector<int> count(26, 0);
    for (const char& c : t) count[c - 'a']++;
    for (const char& c : s) count[c - 'a']--;
    for (int i = 0; i < 26; i++) {
      if (count[i]) return 'a' + i;
    }
    return ' ';
  }
};

class Solution_4 {
public:
  char findTheDifference(string s, string t) {
    char result = t[0];
    for(int i = 0; i < s.size(); ++i) {
      result ^= s[i]^ t[i+1];
    }
    return result;
  }
};
