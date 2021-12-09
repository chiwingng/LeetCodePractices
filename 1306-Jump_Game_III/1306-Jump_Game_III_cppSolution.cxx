class Solution {
public:
  bool canReach(vector<int>& arr, int start) {
    int bound = arr.size();
    // BFS search
    queue<int> my_q;
    my_q.push(start);
    while (!my_q.empty()) {
      int curr = my_q.front();
      my_q.pop();
      // base case: we reached the end!
      if (arr[curr] == 0) return true;
      // negative: we visited this element already
      if (arr[curr] < 0) continue;
      // check each possibility and push it to the queue
      int jump = curr - arr[curr];
      if (jump >= 0 && arr[jump] >= 0) my_q.push(jump);
      jump = curr + arr[curr];
      if (jump < bound && arr[jump] >= 0) my_q.push(jump);
      // mark curr element as visited
      arr[curr] = -arr[curr];
    }
    // we have exhausted all reachable elements but not reaching 0
    return false;
  }
};
