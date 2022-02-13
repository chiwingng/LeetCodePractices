#include <vector>
#include <algorithm>

class Solution {
  vector<int> size;   // size of each disjoint set
  vector<int> parent; // parent of each element
  int findParent(int i) {
    while (parent[i] != i) {
      parent[i] = parent[parent[i]]; // path compression
      i = parent[i];
    }
    return i;
  }
  int unite(int i, int j) {
    if (i == j) return 0;
    int pi = findParent(i), pj = findParent(j);
    if (pi == pj) return size[pi]; // if parents are equal, they are already in the same set
    if (size[pj] < size[pi]) swap(pi, pj); // merge smaller set into larger set
    parent[pi] = pj;
    size[pj] += size[pi];
    return size[pj]; // return the merged set size for comparison
  }
public:
  int earliestAcq(vector<vector<int>>& logs, int n) {
    sort(logs.begin(), logs.end()); // sort by timestamp
    size = vector<int>(n, 1); // initially each set has 1 element
    parent = vector<int>(n);  
    for (int i = 0; i < n; i++) parent[i] = i; // all elements have themselves as parent
    
    for (const vector<int>& log : logs) {
      int time = log[0];
      if (unite(log[1], log[2]) == n) return time; // merge the two friend sets, if the merged set has size n, we are done.
    }
    // there are no sets of size n, the n people are never all friends.
    return -1;
  }
};
