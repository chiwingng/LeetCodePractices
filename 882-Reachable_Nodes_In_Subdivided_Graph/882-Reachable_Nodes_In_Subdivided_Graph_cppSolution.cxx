typedef pair<int, int> pii;
class Solution {
public:
  int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
    // store all connected nodes in graph
    vector< vector<pii> > graph(n);
    for (vector<int>& e : edges) {
      graph[e[0]].push_back({e[1], e[2]});
      graph[e[1]].push_back({e[0], e[2]});
    }
    // map storing smallest distance from 0 to all nodes
    unordered_map<int, int> dist;
    dist[0] = 0;
    for (int i = 1; i < n; i++) dist[i] = maxMoves+1;
    
    // map storing used nodes in each direction
    map<pii, int> used;
    
    // min heap using distances from origin of nodes
    priority_queue< pii, vector<pii>, greater<pii> > myQueue;
    myQueue.push({0,0});
    
    int result = 0;
    
    // loop over all nodes
    while(!myQueue.empty()) {
      // take the node closest to origin
      pii nodeInfo = myQueue.top();
      myQueue.pop();
      int d = nodeInfo.first, node = nodeInfo.second;
      // skip duplicated nodes in the queue
      if (d > dist[node]) continue;
      
      // node is reached for the first time, increment the answer
      result++;
      
      // loop over all neighbors of node
      for (pii& nw : graph[node]) {
        int neighbor = nw.first, weight = nw.second;
        // only maxMoves - d moves are available for further movement after node
        used[{node, neighbor}] = min(weight, maxMoves - d);
        
        // distance to neighbor from origin
        int d2 = d + weight + 1;
        if (d2 < dist[neighbor]) {
          myQueue.push({d2, neighbor});
          dist[neighbor] = d2;
        }
      }
    }
    // loop over all edges to add all intermediate nodes visited
    for (vector<int>& e : edges) {
      result += min(e[2], used[{e[0], e[1]}] + used[{e[1], e[0]}]);
    }
    return result;
  }
};
