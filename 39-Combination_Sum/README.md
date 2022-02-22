# 39. Combination Sum

LeetCode Problem Link: <https://leetcode.com/problems/combination-sum/>

## Description

Given an array of **distinct** integers `candidates` and a target integer `target`, return *a list of all* ***unique combinations*** *of `candidates` where the chosen numbers sum to `target`*. You may return the combinations in **any order**.

The **same** number may be chosen from `candidates` an **unlimited number of times**. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

It is **guaranteed** that the number of unique combinations that sum up to `target` is less than `150` combinations for the given input.

## Constraints

- `1 <= candidates.length <= 30`
- `1 <= candidates[i] <= 200`
- All elements of candidates are **distinct**.
- `1 <= target <= 500`

## Solution Thoughts

### Observations

- For problems searching for all combinations satisfying a certain criteria, [backtracking](https://en.wikipedia.org/wiki/Backtracking) should be the first algorithm that comes to mind.
   - Incrementally builds candidates to the solution, and discards (or "backtrack") them as soon as they are not leading to a final solution.

### Logic

- Maintain a candidate `list` that grows as we traverse through the list, and a remaining target number `remain`.
- For each element, we perform the following:
   - If `remain == 0`, that means we have a combination that sums up to `target`. Append the `list` to our result.
   - Otherwise if the remaining target is negative, that means we exceeded the target already, the candidate list is discarded.
   - We loop over all possible candidates to include in the list and append them to `list`.
      - After backtracking on each of the candidate lists, the appended element is poped out to recover the original state.
      - The previous elements will not be included again to avoid duplicated combinations.
### Complexities

Let `N` be the number of elements in `candidates`, `T` be the value of target and `M` be the minimum candidate value.
- **Time Complexity** = `O(N^(T/M + 1))`
   - The backtracking algorithm can be thought of as going through an `N`-ary execution tree of depth `T/M`, and the time complexity would be `O(N^(T/M + 1))`.
   - An exellent explanation is available in this [solution article](https://leetcode.com/problems/combination-sum/solution/).

- **Space Complexity** = `O(T/M)`
   - Both the function callstack and combination `list` consumes `O(T/M)` space.

## Examples

### Example 1

> **Input**: candidates = [2,3,6,7], target = 7
>
> **Output**: [[2,2,3],[7]]
>
> **Explanation**: 2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
>
> 7 is a candidate, and 7 = 7.
>
> These are the only two combinations.

### Example 2

> **Input**: candidates = [2,3,5], target = 8
>
> **Output**: [[2,2,2,2],[2,3,3],[3,5]]

### Example 3

> **Input**: candidates = [2], target = 1
>
> **Output**: []
