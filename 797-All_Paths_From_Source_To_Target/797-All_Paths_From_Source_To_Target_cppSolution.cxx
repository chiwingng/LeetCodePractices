#include <vector>

class Solution {
  int target;
public:
  std::vector<std::vector<int>> allPathsSourceTarget(const std::vector<std::vector<int>>& graph) {
    target = graph.size() - 1;
    std::vector<std::vector<int>> result;
    std::vector<int> path;
    // DFS starting at node 0
    pathHelper(graph, result, 0, path);
    return result;
  }
  void pathHelper(const std::vector<std::vector<int>>& graph, std::vector<std::vector<int>>& paths, int source, std::vector<int>& path) {
    // we reached a new node, add it to our path
    path.push_back(source);
    // we have a valid path when we reach the target
    if (source == target) paths.push_back(path);
    else {
      // if we haven't reached the target, continue with the DFS
      for (const int& n : graph[source]) {
        // since we are concerning DAGs only, we don't need to keep a std::vector of visited status of the nodes
        pathHelper(graph, paths, n, path);
      }
    }
    // uncheck the current node to continue with the next node in DFS
    path.pop_back();
  }
};
