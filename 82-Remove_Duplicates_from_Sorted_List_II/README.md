# 82. Remove Duplicates from Sorted List II

LeetCode Problem Link: <https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/>

## Description

Given the `head` of a sorted linked list, *delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list*. Return *the linked list* ***sorted*** *as well*.

## Constraints

- The number of nodes in the list is in the range `[0, 300]`.
- `-100 <= Node.val <= 100`
- The list is guaranteed to be **sorted** in ascending order.

## Solution Thoughts

### Observations

- It is also possible to delete the `head`, so we need a `dummyHead` as a previous node to record the actual starting node of the returned linked list.
- We need to skip ALL duplicated nodes, not leaving one behind.
- Edge cases include:
   - Consecutive duplicated elements as in example 1 below.
   - List starting and/or ending with duplicated elements.

### Logic

- Create a `dummyHead` node which has `head` as its next, a `curr` node indicating the endpoint of the current processed linked list, and a `nextNode` node iterating through the list.
- While `nextNode` is not NULL:
   - Check if `nextNode` and `nextNode->next` have the same value
      - if yes we need to skip all of the same-valued nodes. Do that with a while loop and at the end assign `curr->next` to `nextNode->next` as it's the first node that is not the same value as those before.
      - if no we can simply advance the `curr` node.
   - Advance the `nextNode` node for the next iteration.
- Return the `next` of `dummyHead`.

### Complexities

- **Time Complexity** = `O(N)`
   - We traverse the whole list exactly once.

- **Space Complexity** = `O(1)`
   - We keep only 3 extra nodes to track the process.

## Examples

### Example 1

> **Input**: head = [1,2,3,3,4,4,5]
>
> **Output**: [1,2,5]

### Example 2

> **Input**: [1,1,1,2,3]
>
> **Output**: [2,3]
