class Solution {
public:
  bool detectCapitalUse(string word) {
    bool startWithCapital = word[0] < 'a';
    bool tailNoCapital = true;
    bool tailAllCapital = true;
    for (int i = 1; i < word.size(); i++) {
      if (word[i] < 'a') tailNoCapital = false;
      else tailAllCapital = false;
    }
    return tailNoCapital || (startWithCapital && tailAllCapital);
  }
};
