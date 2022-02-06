# 333. Largest BST Subtree

LeetCode Problem Link: <https://leetcode.com/problems/largest-bst-subtree/>

## Description

Given the root of a binary tree, find the largest subtree, which is also a Binary Search Tree (BST), where the largest means subtree has the largest number of nodes.

A Binary Search Tree (BST) is a tree in which all the nodes follow the below-mentioned properties:

- The left subtree values are less than the value of their parent (root) node's value.
- The right subtree values are greater than the value of their parent (root) node's value.

Note: A subtree must include all of its descendants.

## Constraints

- The number of nodes in the tree is in the range `[0, 10^4]`
- `-10^4 <= Node.val <= 10^4`

## Solution Thoughts

### Observations

- The validness of BST is determined by validness of children and value of node.
- To avoid repeated traversals, post-order traversal is the best traversing approach.
- Several information are needed for determination:
   - Min. value of right subTree
   - Max. value of left subTree
   - Max. size of BST subtree under the node (if the node is valid BST, this is the count of nodes)

### Logic

- For every node, return a class called nodeInfo containing `min_v`, `max_v`, `max_size` and validness of BST at current node.
- An empty node will return the max. INT value as `min_v`, min. INT value as `max_v`, and 0 as `max_size`.
   - An empty node as a right subtree needs to compare its `min_v` to the parent's value, and it needs to be larger than any INT values to ensure it doesn't affect the determination of BST.
   - Similar logic goes to the `max_v` value.
   - An empty node is of course a valid BST with size 0.
- A valid BST node will return the minimum of all min_v, maximum of all max_v, sum of left and right `max_size`s plus 1 as its `max_size`.
- An invalid BST node will return completely invalid info: min. INT value as `min_v`, max. INT value as `max_v`, max. of left and right `max_size`s as its `max_size`.
   - So that we keep track of the largest BST under the current node.

## Examples

### Example 1

> **Input**: root = [10,5,15,1,8,null,7]
>
> **Output**: 3
>
> **Explanation**: The Largest BST Subtree in this case is the highlighted one. The return value is the subtree's size, which is 3.
<pre>
Tree Diagram:
    10
   /  \
  **5**   15
 / \    \
**1**   **8**    7
</pre>

### Example 2

> **Input**: root = [4,2,7,2,3,5,null,2,null,null,null,null,null,1]
>
> **Output**: 2