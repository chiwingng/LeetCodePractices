# 24. Swap Nodes in Pairs

LeetCode Problem Link: <https://leetcode.com/problems/swap-nodes-in-pairs/>

## Description

Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)

## Constraints

- The number of nodes in the list is in the range `[0, 100]`.
- `0 <= Node.val <= 100`

## Solution Thoughts

### Observations

- There are two ways to solve the problem: recursive and iterative. Both are essentially the same algorithm.

### Logic

- Recursive:
   - Base case: we have 1 node or no nodes left, simply return the input `node`.
   - General case: `1 -> 2 -> 3`
      - Record `2` as `child`. (as `1.next` will change in the next step)
      - Connect `1` to the result of `swapPairs(3)` (assuming the swapPairs function will swap the rest of the list properly)
      - Connect `2` to `1` to finish the swap.
      - The head now is `2`, so
- Iterative:
   - Similar to recursive, but we swap the nodes on the fly:
   - Create a `dummy` node to indicate the start of list and connect it to the input `head`.
   - We iterate until `head` and `head.next` are both valid (so that we can swap them), at the same time maintain a `prev` node as the parent node of `head`
   - Continue to use `dummy->1->2->3` as an example, now `prev = dummy`, `head = 1`, `head.next = 2`.
      - Connect `prev` to `head.next` (dummy -> 2)
      - Connect `head` to `head.next.next` (1 -> 3)
      - Connect `prev.next` to `head` (2 -> 1)
      - The list now becomes: `dummy->2->1->3`
      - Now move `prev` to `head` (`prev = 1`) and `head` to `head.next` (`head = 3`) to continue the next iteration.

### Complexities

- **Time Complexity** = `O(N)`
   - Both recursive and iterative procedures take `O(N)` time to traverse once through the list.

- **Space Complexity** = `O(N)` (recursive) or `O(1)` for iterative
   - For recursive procedure, the call stack has depth `N/2 = O(N)`
   - For iterative procedure, we maintain 2 extra nodes in total, so it consumes `O(1)` space.

## Examples

### Example 1

> **Input**: head = [1,2,3,4]
>
> **Output**: [2,1,4,3]

### Example 2

> **Input**: []
>
> **Output**: []

### Example 3

> **Input**: [1]
>
> **Output**: [1]
