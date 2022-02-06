# 563. Binary Tree Tilt

LeetCode Problem Link: <https://leetcode.com/problems/binary-tree-tilt/>

## Description

Given the `root` of a binary tree, return **the sum of every tree node's** ***tilt***.

The tilt of a tree node is the absolute difference between the sum of all left subtree node values and all right subtree node values. If a node does not have a left child, then the sum of the left subtree node values is treated as 0. The rule is similar if there the node does not have a right child.

## Constraints

- The number of nodes in the tree is in the range `[0, 10^4]`.
- `-1000 <= Node.val <= 1000`

## Solution Thoughts

### Observations

- Tilt of a node depends completely on the sum of node values from the left and right subtree.
   - Hence post-order traversal is the best approach.
- Recursion function should update a global variable that sums up all tilts, while returning the sum of all node values.

### Logic

- The `getSum` function computes the sum of node values from the left and right subtrees by recursion.
   - If the node is empty, it will simply return 0.
   - The current node's tilt value is added to the global `tilt` variable.
   - The sum of left, right sums and node value is returned.
- The `fildTilt` function will simply run `getSum` on the root node and return the global `tilt` value after computation.

## Examples

### Example 1

> **Input**: root = [1,2,3]
>
> **Output**: 1
>
> **Explanation**: 
<pre>
Tree Diagram:
    1          1
   / \   -->  / \
  2   3      0   0
</pre>
> Tilt of node 2 : |0-0| = 0 (no children)
>
> Tilt of node 3 : |0-0| = 0 (no children)
>
> Tilt of node 1 : |2-3| = 1 (left subtree is just left child, so sum is 2; right subtree is just right child, so sum is 3)
>
> Sum of every tilt : 0 + 0 + 1 = 1

### Example 2

> **Input**: root = [4,2,9,3,5,null,7]
>
> **Output**: 15
>
> **Explanation**: 
<pre>
Tree Diagram:
     4                6
   /   \            /   \
  2     9    -->   2     7
 / \     \        / \     \
3   5     7      0   0     0
</pre>
> Tilt of node 3 : |0-0| = 0 (no children)
>
> Tilt of node 5 : |0-0| = 0 (no children)
>
> Tilt of node 7 : |0-0| = 0 (no children)
>
> Tilt of node 2 : |3-5| = 2 (left subtree is just left child, so sum is 3; right subtree is just right child, so sum is 5)
>
> Tilt of node 9 : |0-7| = 7 (no left child, so sum is 0; right subtree is just right child, so sum is 7)
>
> Tilt of node 4 : |(3+5+2)-(9+7)| = |10-16| = 6 (left subtree values are 3, 5, and 2, which sums to 10; right subtree values are 9 and 7, which sums to 16)
>
> Sum of every tilt : 0 + 0 + 0 + 2 + 7 + 6 = 15

### Example 3

> **Input**: root = [21,7,14,1,1,2,2,3,3]
>
> **Output**: 9