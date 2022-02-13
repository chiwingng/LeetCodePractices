# 1101. The Earliest Moment When Everyone Become Friends

LeetCode Problem Link: <https://leetcode.com/problems/the-earliest-moment-when-everyone-become-friends/>

## Description

There are n people in a social group labeled from `0` to `n - 1`. You are given an array `logs` where `logs[i] = [timestamp_i, x_i, y_i]` indicates that `x_i` and `y_i` will be friends at the time `timestamp_i`.

Friendship is **symmetric**. That means if `a` is friends with `b`, then `b` is friends with `a`. Also, person `a` is acquainted with a person `b` if `a` is friends with `b`, or `a` is a friend of someone acquainted with `b`.

Return *the earliest time for which every person became acquainted with every other person*. If there is no such earliest time, return `-1`.

## Constraints

- `2 <= n <= 100`
- `1 <= logs.length <= 10^4`
- `logs[i].length == 3`
- `0 <= timestamp_i <= 10^9`
- `0 <= x_i, y_i <= n - 1`
- `x_i != y_i`
- All the values `timestamp_i` are unique.
- All the pairs `(x_i, y_i)` occur at most one time in the input.

## Solution Thoughts

### Observations

- The Disjoint Set Union (a.k.a. UnionFind) structure is ideal for this problem:
   - Friendships are symmetric.
   - Acquaintances are not constrained by depth

### Logic

- Construct a DSU data structure with `n` elements.
- Loop over all logs sorted in time:
   - Unite the two elements (people) by size, i.e. setting the parent of smaller-sized set to the parent of the larger-sized set.
   - Once the size of any set reaches `n`, all people become friends, return the `timestamp`.
- If there are no sets of size `n` after the loop, return `-1` indicating the people are never all friends.

### Complexities

Let `N` be the number of people and `M` be the number of logs.

- **Time Complexity** = O(N + Mlog(M) + M&alpha(N))
   - `O(N)` time is used to create the DSU data structure.
   - `O(M log(M))` time is used to sort the logs.
   - `O(M&alpha(N))` time is used to perform the `M` union/find operations on `N` elements, where `&alpha(N)` is the Inverse Ackermann Function.

- **Space Complexity** = `O(N + log(M))`
   - DSU data structure consumes `O(N)` space.
   - Sorting `M` elements in C++ or Java consumes `O(log(M))` for callstack.

## Examples

### Example 1

> **Input**: logs = [[20190101,0,1],[20190104,3,4],[20190107,2,3],[20190211,1,5],[20190224,2,4],[20190301,0,3],[20190312,1,2],[20190322,4,5]], n = 6
>
> **Output**: 20190301
>
> **Explanation**:
>
> The first event occurs at timestamp = 20190101 and after 0 and 1 become friends we have the following friendship groups [0,1], [2], [3], [4], [5].
>
> The second event occurs at timestamp = 20190104 and after 3 and 4 become friends we have the following friendship groups [0,1], [2], [3,4], [5].
>
> The third event occurs at timestamp = 20190107 and after 2 and 3 become friends we have the following friendship groups [0,1], [2,3,4], [5].
>
> The fourth event occurs at timestamp = 20190211 and after 1 and 5 become friends we have the following friendship groups [0,1,5], [2,3,4].
>
> The fifth event occurs at timestamp = 20190224 and as 2 and 4 are already friends anything happens.
>
> The sixth event occurs at timestamp = 20190301 and after 0 and 3 become friends we have that all become friends.

### Example 2

> **Input**: logs = [[0,2,0],[1,0,1],[3,0,3],[4,1,2],[7,3,1]], n = 4
>
> **Output**: 3

