# 2. Add Two Numbers

LeetCode Problem Link: <https://leetcode.com/problems/add-two-numbers/>

## Description

You are given two **non-empty** linked lists representing two non-negative integers. The digits are stored in **reverse order**, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

## Constraints

- The number of nodes in each linked list is in the range `[1, 100]`.
- `0 <= Node.val <= 9`
- It is guaranteed that the list represents a number that does not have leading zeros.

## Solution Thoughts

### Observations

- The problem can be solved by performing elementary summation digit by digit.
- Need to record the carry-over digit

### Logic

- Iterative solution:
   - Create a dummy `head` node to indicate the start of result list.
   - Create a `curr` node to record the position of result list iteration.
   - As we iterate through `l1` and `l2` until both of them are null
      - We perform the sum of digits with carry-over (if the nodes are non-null)
      - The next node in result list has value `sum % 10`
      - The carry over value is `sum / 10`
      - We advance `curr`, `l1` and `l2` if they are non-null.
   - If we have extra carry-over here, create one more node at the end of the result list.
   - Return `head->next`.
- Recursive solution:
   - Check if both nodes are null, if yes we return a null node.
   - If any of `l1` and `l2` are null, we create a dummy node of value 0 for convenience purpose
      - Equivalent to padding leading 0's to achieve the same length
   - Perform the sum by adding the two values
   - If we need to carry over value, we increment any of the next node, if they exist
      - If none of the next nodes exist, we create a next node for `l1` and set its value to 1.
   - Return a new node with value `sum % 10` and next node of `addTwoNumbers(l1->next, l2->next)`.

### Complexities

Let `M` be the length of `l1` and `N` be the length of `l2`.

- **Time Complexity** = `O(max(M,N))`
   - We iterate until the end of the result list of length `O(max(M,N))`, in each iteration performing `O(1)` operations.

- **Space Complexity** = `O(1)` (iterative) or `O(max(M,N))`
   - For the iterative solution, we keep only a carry over number and two nodes.
   - For the recursive solution, we have a function callstack of depth `O(max(M,N))`.

## Examples

### Example 1

> **Input**: l1 = [2,4,3], l2 = [5,6,4]
>
> **Output**: [7,0,8]
>
> **Explanation**: 342 + 465 = 807.

### Example 2

> **Input**: l1 = [0], l2 = [0]
>
> **Output**: [0]

### Example 3

> **Input**: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
>
> **Output**: [8,9,9,9,0,0,0,1]
