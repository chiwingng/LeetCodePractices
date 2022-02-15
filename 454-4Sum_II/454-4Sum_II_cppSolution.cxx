class Solution {
public:
  int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
    unordered_map<long, int> count;
    for (const int n1 : nums1) {
      for (const int n2 : nums2) {
        count[n1+n2]++;
      }
    }
    
    int result = 0;
    for (const int& n3 : nums3) {
      for (const int& n4 : nums4) {
        result += count[-n3-n4];
      }
    }
    return result;
  }
};

// A more general kSumCount can be solved in a similar way
// splitting the k arrays into 2 groups, record the count of every possible sum of tuples of elements from the first group
// and then for every possible sum in the second group, find the count of its negative value in the hash map.
// Time and Space complexity: O(N^(k/2))

// If we are tight in memory, we can move arrays from first to second group to reduce the number of elements stored in the map
// Time complexity will go up accordingly.
