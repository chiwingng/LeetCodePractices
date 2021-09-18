class Solution {
public:
  vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> counts;
    for (int& n : nums1) counts[n]++;
    int count = 0;
    for (int& n : nums2) {
      if (counts[n] > 0) {
        nums1[count++] = n;
        counts[n]--;
      }
    }
    nums1.resize(count);
    return nums1;
  }
};
