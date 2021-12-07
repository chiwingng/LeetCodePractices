\1;95;0c# 366. Find Leaves of Binary Tree

LeetCode Problem Link: <https://leetcode.com/problems/find-leaves-of-binary-tree/>

## Description

Given the root of a binary tree, collect a tree's nodes as if you were doing this:

- Collect all the leaf nodes.
- Remove all the leaf nodes.
- Repeat until the tree is empty.

## Constraints

- The number of nodes in the tree is in the range [1, 100].
- `-100 <= Node.val <= 100`

## Examples

### Example 1

> **Input**: root = [1,2,3,4,5]
>
> **Output**: [[4,5,3],[2],[1]]
>
<pre>
Tree Diagram:
    1              1          1
   / \            /
  2   3    --->  2     ---> 
 / \
4   5
</pre>
> **Explanation**:
>
> [[3,5,4],[2],[1]] and [[3,4,5],[2],[1]] are also considered correct answers since per each level it does not matter the order on which elements are returned.

### Example 2

> **Input**: root = [1]
>
> **Output**: [[1]]