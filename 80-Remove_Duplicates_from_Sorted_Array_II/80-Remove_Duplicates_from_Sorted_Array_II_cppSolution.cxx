class Solution {
public:
  int removeDuplicates(vector<int>& nums) {
    int loc = 1, val = nums[0], count = 1;
    
    for (int curr = 1; curr < nums.size(); curr++) {
      // we have a duplicated element
      if (nums[curr] == val) count++;
      else {
        // new element is found
        count = 1;
        val = nums[curr];
      }
      // if the current element is not duplicated more than twice
      // increment the first pointer to write a new element
      if (count <= 2) nums[loc++] = val;
    }
    return loc;
  }
};
