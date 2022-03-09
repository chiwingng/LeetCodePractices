# 21. Merge Two Sorted Lists

LeetCode Problem Link: <https://leetcode.com/problems/merge-two-sorted-lists/>

## Description

You are given the heads of two sorted linked lists `list1` and `list2`.

Merge the two lists in a one **sorted** list. The list should be made by splicing together the nodes of the first two lists.

Return *the head of the merged linked list*.

## Constraints

- The number of nodes in both lists is in the range `[0, 50]`.
- `-100 <= Node.val <= 100`
- Both `list1` and `list2` are sorted in **non-decreasing** order.

## Solution Thoughts

### Observations

- The two lists are already sorted, so we can compare just the first elements of both lists to get the smallest element.
- Once we reached the end of one of the lists, we can simply append the other list to the end of merged list.
- Both recursion and iteration can solve the problem.

### Logic

- Recursion:
   - Check if one of the lists is exhausted, if so return the other.
   - Take the list node with the smaller element, set its next node to be the result of `mergeTwoLists` of the next node and the other list.
   - Return the smaller node after setting its next.
- Iteration:
   - Create a `dummy` node to record its head and a `curr` node for the end of current merged list.
   - We need to compare until both lists are still non-empty:
      - We assume the value of node `list1` is smaller than `list2`. If not, simply `swap` them.
      - Append `list1` to `curr`, then move both `curr` and `list1` to their next node.
   - After one of the lists exhausted, simply append the other list to `curr`, then we are done.

### Complexities

Let `N` be the number of nodes in `list1` and `M` be the number of nodes in `list2`.

- **Time Complexity** = `O(N+M)`
   - We traverse all the elements in the two lists at most once.

- **Space Complexity** = `O(N+M)` or `O(1)`
   - For the recursion method, the callstack only returns until one of the ends is reached.
   - For the iteration method, we keep only two extra nodes for tracking purpose.

## Examples

### Example 1

> **Input**: list1 = [1,2,4], list2 = [1,3,4]
>
> **Output**: [1,1,2,3,4,4]

### Example 2

> **Input**: list1 = [], list2 = []
>
> **Output**: []

### Example 3

> **Input**: list1 = [], list2 = [0]
>
> **Output**: [0]
