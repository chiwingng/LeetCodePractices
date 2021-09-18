class RLEIterator {
public:
  RLEIterator(vector<int>& encoding): _encoding(encoding), index(0) {}
  
  int next(int n) {
    for (; index < _encoding.size(); index += 2) {
      if (n <= _encoding[index]) {
        _encoding[index] -= n;
        return _encoding[index+1];
      }
      n -= _encoding[index];
    }
    return -1;
  }
private:
  vector<int> _encoding;
  int index;
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */
