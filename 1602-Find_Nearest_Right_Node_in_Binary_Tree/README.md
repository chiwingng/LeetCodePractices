# 1602. Find Nearest Right Node in Binary Tree

LeetCode Problem Link: <https://leetcode.com/problems/find-nearest-right-node-in-binary-tree/>

## Description

Given the `root` of a binary tree and a node `u` in the tree, return *the* ***nearest*** *node on the* ***same level*** *that is to the* ***right*** *of `u`, or return `null` if `u` is the rightmost node in its level*.

## Constraints

- The number of nodes in the tree is in the range `[1, 10^5]`.
- `1 <= Node.val <= 10^5`
- All values in the tree are distinct.
- `u` is a node in the binary tree rooted at `root`.

## Solution Thoughts

### Observations

- Since we need the left-right information of tree nodes, a level-order traversal/BFS is a natural choice.
- If the right-most node in a level is queried, then we need to return `null` instead of the first node in next level, so we need to separate different levels in the tree.
   - This can be achieved by a count of nodes at the beginning of each level.

### Logic

- A queue is constructed to perform BFS.
- At the beginning of each level, a variable `count` is initialized to be the size of queue and decremented each time a node is poped out.
- For each node within the current level:
   - If the previous node is the node to find, then we return the current node.
   - Check if the current node is the node to find.
- If we reached the end and find that the last node is the node we want, return `null`.

### Complexities

- **Time Complexity** = `O(N)`
   - Since we have to visit every node in the traversal once.

- **Space Complexity** = `O(D)`
   - We need to store every node in a level (diameter `D`), the worse case is the last level which contains at most `N/2` nodes.

## Examples

### Example 1

> **Input**: root = [1,2,3,null,4,5,6], u = 4
>
> **Output**: 5
>
> **Explanation**: The nearest node on the same level to the right of node 4 is node 5.
>
<pre>
Tree Diagram:
     1
   /   \
  2     3
   \   / \
    **4** 5   6
</pre>

### Example 2

> **Input**: root = [3,null,4,2], u = 2
>
> **Output**: null
>
> **Explanation**: There are no nodes to the right of 2.
>
<pre>
Tree Diagram:
    3
     \
      4
     /
    2
</pre>