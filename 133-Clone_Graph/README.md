# 133. Clone Graph

LeetCode Problem Link: <https://leetcode.com/problems/clone-graph/>

## Description

Given a reference of a node in a **connected** undirected graph.

Return a **deep copy** (clone) of the graph.

Each node in the graph contains a value (`int`) and a list (`List[Node]`) of its neighbors.

    class Node {
      public int val;
      public List<Node> neighbors;
    }
 

**Test case format:**

For simplicity, each node's value is the same as the node's index (1-indexed). For example, the first node with `val == 1`, the second node with `val == 2`, and so on. The graph is represented in the test case using an adjacency list.

**An adjacency list** is a collection of unordered **lists** used to represent a finite graph. Each list describes the set of neighbors of a node in the graph.

The given node will always be the first node with `val = 1`. You must return the **copy of the given node** as a reference to the cloned graph.

## Constraints

- The number of nodes in the graph is in the range `[0, 100]`.
- `1 <= Node.val <= 100`
- `Node.val` is unique for each node.
- There are no repeated edges and no self-loops in the graph.
- The Graph is connected and all nodes can be visited starting from the given node.

## Solution Thoughts

### Observations

- We need to make copies of nodes as we traverse along the graph, starting with the given reference node `1`.
- To build the correct graph, we need to avoid making duplicated copies along the way as that would mess up the edges.
   - To achieve this, a hashmap of old nodes to new nodes can be built.
- Both DFS and BFS are valid to solve this problem, among which the DFS or recursive solution is easier to write.
   - DFS takes `O(H)` space for the recursion stack, while BFS takes `O(W)` space for the queue (`H` is the height, and `W` is the width of the graph, if we represent it as a tree)
   - One can choose one of them if we know which kind of graph is given.

### Logic

- For both methods:
   - Maintain an `oldToNew` hashmap to mark already cloned nodes.
   - Directly return `null` if the input is `null`.
   - Along the traversal if we see nodes that are already cloned, we can simply use the created copy.
- DFS/Recursive:
   - Create a new node `c'` using the value of the current node `c`, then insert it into the hashmap. (`oldToNew[c] = c'`)
   - For each neighbor `n` of the current node `c`, create a copy `n'` by calling `cloneGraph` on `n`, and push `n'` to the neighbor array of the copy `c'`.
   - Return the new node `c'`.
- BFS:
   - Add the input node to a queue.
   - Standard BFS traversal:
      - Pop a node `n` from the front of queue.
      - Visit all neighbors of the current node `n`.
      - If any of the neighbors was visited, then get its clone from the hashmap. Otherwise create a clone, store it in the hashmap, and add the old node to the queue.
      - Add the clone of all neighbors to the neighbor of `n`.
   - Return the clone of starting node read from the hashmap.

### Complexities

Let `N` be the number of nodes and `E` be the number of edges in the graph.

- **Time Complexity** = `O(N + E)`
   - For both methods, we need to traverse over all nodes and edges. For all these elements, `O(1)` operations are performed like hashmap insertion and loopup.

- **Space Complexity** = `O(N)`
   - For DFS, the complexity is `O(H)`; for BFS the complexity is `O(W)` as described above. In worst cases both would degrade to `O(N)`.

## Examples

### Example 1

> **Input**: adjList = [[2,4],[1,3],[2,4],[1,3]] (representing the graph)
>
> **Output**: [[2,4],[1,3],[2,4],[1,3]] (with different nodes than the input)
>
> **Explanation**: There are 4 nodes in the graph.
>
> 1st node (val = 1)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
>
> 2nd node (val = 2)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).
>
> 3rd node (val = 3)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
>
> 4th node (val = 4)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).

### Example 2

> **Input**: adjList = [[]]
>
> **Output**: [[]]
>
> **Explanation**: Note that the input contains one empty list. The graph consists of only one node with val = 1 and it does not have any neighbors.

### Example 3

> **Input**: []
>
> **Output**: []
>
> **Explanation**: This an empty graph, it does not have any nodes.
