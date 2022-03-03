class Solution {
public:
  int numberOfArithmeticSlices(vector<int>& nums) {
    // skip if nums has fewer elements than required
    if (nums.size() < 3) return 0;
    // record the difference in arithmetic sequence
    int diff = nums[1] - nums[0];
    // the result and length of sequence (beyond the first two)
    int result = 0, length = 0;
    // start from the third element
    for (int i = 2; i < nums.size(); i++) {
      // the new difference
      int newdiff = nums[i] - nums[i-1];
      // the arithmetic sequence (AS) is truncated
      if (newdiff != diff) {
        // process the previous sequence
        result += length*(length+1)/2;
        // re-initialize the new sequence
        diff = newdiff;
        length = 0;
      }
      // AS continued
      else length++;
    }
    // tackle with the final sequence
    return result + length*(length+1)/2;
  }
};
