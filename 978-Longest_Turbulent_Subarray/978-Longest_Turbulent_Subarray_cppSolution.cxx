class Solution {
public:
  int maxTurbulenceSize(vector<int>& arr) {
    int result = 1, n_num = arr.size(), up = 1, down = 1;
    for (int i = 1; i < n_num; i++) {
      if (arr[i] < arr[i-1]) {
        down = up + 1; up = 1;
        result = max(result, down);
      }
      else if (arr[i] > arr[i-1]) {
        up = down + 1; down = 1;
        result = max(result, up);
      }
      else {
        up = 1; down = 1;
      }
    }
    return result;
  }
};
