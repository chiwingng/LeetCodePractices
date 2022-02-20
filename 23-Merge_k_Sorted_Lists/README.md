# 23. Merge k Sorted Lists

LeetCode Problem Link: <https://leetcode.com/problems/merge-k-sorted-lists/>

## Description

You are given an array of `k` linked-lists `lists`, each linked-list is sorted in ascending order.

*Merge all the linked-lists into one sorted linked-list and return it*.

## Constraints

- `k == lists.length`
- `0 <= k <= 10^4`
- `0 <= lists[i].length <= 500`
- `-10^4 <= lists[i][j] <= 10^4`
- `lists[i]` is sorted in ascending order.
- The sum of `lists[i].length` will not exceed 10^4.

## Solution Thoughts

### Observations

- Although comparing `k` values in general takes `O(k)` times, since we only need the smallest value each time, we can optimize the time complexity to `O(log(k))` by using Priority Queue.

### Logic

- Put all k linked-list nodes into a priority queue.
- Each time take the top node and append it to the result linked list
   - if the current node has next, push its next into the priority queue
   - A slight optimization can be done by skipping the loop where only one node is left in the priority queue: the partial list is already sorted.

### Complexities

Assume `N` to be the total number of nodes, and there are `k` input linked-lists.
- **Time Complexity** = `O(N log(k))`
   - For each of the `N` nodes to be inserted into the priority queue, it costs `O(log k)` time to find the correct position.
   - For each of the `N` nodes to be poped from the queue and linked to the final list, it costs only `O(1)` time.

- **Space Complexity** = `O(k)`
   - The `O(N)` space used for the final answer is actually reused from the inputs.
   - The priority queue holds at most `k` elements at a time, so it consumes `O(k)` memory. (In most cases `k << N` except when there are only one element per list.)

## Examples

### Example 1

> **Input**: lists = [[1,4,5],[1,3,4],[2,6]]
>
> **Output**: [1,1,2,3,4,4,5,6]
>
> **Explanation**: The linked-lists are:
>
> [
>
>   1->4->5,
>
>   1->3->4,
>
>   2->6
>
> ]
>
> merging them into one sorted list:
>
> 1->1->2->3->4->4->5->6

### Example 2

> **Input**: lists = []
>
> **Output**: []

### Example 3

> **Input**: lists = [[]]
>
> **Output**: []
