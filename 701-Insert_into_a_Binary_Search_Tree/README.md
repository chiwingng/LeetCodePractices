# 701. Insert into a Binary Search Tree

LeetCode Problem Link: <https://leetcode.com/problems/insert-into-a-binary-search-tree/>

## Description

You are given the `root` node of a binary search tree (BST) and a `value` to insert into the tree. Return *the root node of the BST after the insertion*. It is **guaranteed** that the new value does not exist in the original BST.

Notice that there may exist multiple valid ways for the insertion, as long as the tree remains a BST after insertion. You can return **any of them**.

## Solution Thoughts

### Observations and Logic

- Although there are many possible result trees, the problem only require returning one of them. So we can just implement the easiest one.
- The easiest way is to do a binary search down the tree, and then insert the value at the missing node location at the end of search.
   - It is gauranteed that the constructed tree is a BST.

## Constraints

- The number of nodes in the tree will be in the range `[0, 10^4]`.
- `-10^8 <= Node.val, val <= 10^8`
- All the values `Node.val` are unique.
- It's **guaranteed** that val does not exist in the original BST.

## Examples

### Example 1

> **Input**: root = [4,2,7,1,3], val = 5
>
> **Output**: [4,2,7,1,3,5]
>
> **Explanation**: Another accepted tree is [5,2,7,1,3,null,null,null,null,null,4]
>
> Tree Diagrams:
<pre>
Input Tree   Output Tree   Alternative Output
    4             4               **5**
   / \          /   \            / \
  2   7        2     7          2   7
 / \          / \   /          / \
1   3        1   3 **5**          1   3
                                   \
                                    4
</pre>

### Example 2

> **Input**: root = [40,20,60,10,30,50,70], val = 25
>
> **Output**: [40,20,60,10,30,50,70,null,null,25]

### Example 3

> **Input**: root = [4,2,7,1,3,null,null,null,null,null,null], val = 5
>
> **Output**: [4,2,7,1,3,5]