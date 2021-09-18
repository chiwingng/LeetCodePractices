class Solution {
public:
  int hIndex(vector<int>& citations) {
    int n_papers = citations.size(), left = 0, right = n_papers - 1;
    while (left <= right) {
      int mid = left + (right - left)/2;
      int cites_needed = n_papers - mid;
      if (citations[mid] == cites_needed) return cites_needed;
      if (citations[mid] < cites_needed) left = mid + 1; // we have less cited articles
      else right = mid - 1;
    }
    return n_papers - left;
  }
};
