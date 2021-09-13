class Solution {
public:
  vector< vector<int> > fourSum(vector<int>& nums, int target) {
    if (nums.size() < 4) return vector< vector<int> >();
    // sort the input array
    sort(nums.begin(), nums.end());
    // call kSum function with the full nums array and return the result
    return kSum(nums, 0, 4, target);
  }
private:
  vector< vector<int> > kSum(const vector<int>& nums, const int& start, const int& k, const int& target) {
    // check if the sum of first k elements is larger than target
    if (accumulate(nums.begin()+start, nums.begin() + start + k, long(0)) > target) 
      return vector< vector<int> >();
    // check if the sum of last k elements is smaller than target
    if (accumulate(nums.end()-k, nums.end(), long(0)) < target) 
      return vector< vector<int> >();
    // if k is 2, it's an ordinary twoSum problem with sorted input
    if (k == 2) return twoSum(nums, start, target);
    // iterate over all elements and reduce the problem to one less k
    vector< vector<int> > result;
    for (int i = start; i < nums.size() - k + 1; i++) {
      if (i == start || nums[i] != nums[i-1]) {
        for (vector<int>& subset : kSum(nums, i+1, k-1, target - nums[i])) {
          // push nums[i] to every solution of subproblem
          subset.push_back(nums[i]);
          result.push_back(subset);
        }
      }
    }
    return result;
  }
  vector< vector<int> > twoSum(const vector<int>& nums, const int& start, const int& target) {
    // we will use the two pointer approach
    int low = start, high = nums.size() - 1;
    vector< vector<int> > result;
    while (low < high) {
      long sum = long(nums[low]) + nums[high];
      // if we have a smaller sum
      if (sum < target) {
        // increment until we find a different value
        do {low++;} while (low < high && nums[low] == nums[low-1]);
      }
      // if we have a larger sum
      else if (sum > target) {
        // decrement until we find a different value
        do {high--;} while (low < high && nums[high] == nums[high+1]);
      }
      // we find a pair!
      else {
        result.push_back({nums[low], nums[high]});
        // perform increment and decrements as the above
        do {low++;} while (low < high && nums[low] == nums[low-1]);
        do {high--;} while (low < high && nums[high] == nums[high+1]);
      }
    }
    return result;
  }
};
