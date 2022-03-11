# 61. Rotate List

LeetCode Problem Link: <https://leetcode.com/problems/rotate-list/>

## Description

Given the `head` of a linked list, rotate the list to the right by `k` places.

## Constraints

- The number of nodes in the list is in the range `[0, 500]`.
- `-100 <= Node.val <= 100`
- `0 <= k <= 2 * 10^9`

## Solution Thoughts

### Observations

- We need to attach the end of the list to its head, if we need to rotate by non-zero places.
- Therefore in the process of finding the tail, we can simutaneously count the length `N`.
- Rotation is periodic, so effectively we only need to perform `N - (k % N)` movements to reach the new head
   - `k % N` gives the net number of nodes get moved from the tail to the head of the list
   - Therefore the head of the new list is `N - k % N` positions from the head.
- Simple optimizations include:
   - The list is empty/has only one node/k=0 -> no operations needed.

### Logic

- Count the length of the list, at the end of loop attach the tail to the head to form a ring
   - No need to attach if `k % N == 0` since in this case we can simply return the original list.
- Count `N - k % N` nodes from the head, assign the new head to be the next of this node, then assign null to the next of the current node to break the cycle. (The list ends here)

### Complexities

- **Time Complexity** = `O(N)`
   - The list is traversed at most twice.

- **Space Complexity** = `O(1)`
   - Only an extra node and an integer is used.

## Examples

### Example 1

> **Input**: head = [1,2,3,4,5], k = 2
>
> **Output**: [4,5,1,2,3]
>
> **Explanation**: Node `1` is moved 2 units to the right, the last two nodes are rotated to the head.

### Example 2

> **Input**: head = [0,1,2], k = 4
>
> **Output**: [2,0,1]
