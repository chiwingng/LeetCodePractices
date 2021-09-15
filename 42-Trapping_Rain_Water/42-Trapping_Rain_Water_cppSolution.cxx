class Solution {
public:
  int trap(vector<int>& height) {
    int n_bars = height.size();
    vector<int> water_height(n_bars);
    water_height[0] = height[0];
    for (int i = 1; i < n_bars; i++) {
      water_height[i] = max(water_height[i-1], height[i]);
    }
    int curr_height = 0, result = 0;
    for (int i = n_bars - 1; i >= 0; i--) {
      curr_height = max(curr_height, height[i]);
      result += min(water_height[i], curr_height) - height[i];
    }
    return result;
  }
};
