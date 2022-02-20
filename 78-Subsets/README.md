# 78. Subsets

LeetCode Problem Link: <https://leetcode.com/problems/subsets/>

## Description

Given an integer array `nums` of unique elements, return *all possible subsets (the power set).*

The solution set **must not** contain duplicate subsets. Return the solution in **any order**.

## Constraints

- `1 <= nums.length <= 10`
- `-10 <= nums[i] <= 10`
- All the numbers of nums are **unique**.

## Solution Thoughts

### Observations

- For a set with `N` elements, there are `2^N` possible subsets as each elements can be present or absent.
   - Total number of elements in the superset is: ![equation](<img src="https://latex.codecogs.com/svg.image?O\left(\sum_{i=0}^{N}&space;i\times&space;\binom{N}{i}\right)=O(N\times&space;2^N)" title="O\left(\sum_{i=0}^{N} i\times \binom{N}{i}\right)=O(N\times 2^N)" />)
- The building of power set can be done in several ways, backtracking/recursion, iterative and bit masking.
   - Among the three methods, bit-masking is preferred in interviews:
      - It is the easiest to implement as one generates all possible bit-masks and then build each subset accordingly.
      - It also automatically ensures that no solutions are missing and no duplicated subsets are produced.
      - Lexicographically ordered subsets are generated using this method.

### Logic

We continue to use `N` as the number of elements in the input array.

- **Bit-masking**:
   - Generate bit-masks from 0 to `2^N - 1`.
   - For each bit-mask, build a subset by including the `i`th element from the list if the `i`th bit in the bit-mask is set.

- **Recursive/Backtracking**:
   - Skipped

- **Iterative**:
   - Starting from an empty subset in the final list.
   - For each element in the input list:
      - build subsets by appending this element to all subsets in the final list, and add all of them to the final list

### Complexities

- **Time Complexity** = `O(N * 2^N)`
   - The time is the total number of elements pushed into the final list.

- **Space Complexity** = `O(N)`
   - Ignoring the `O(N * 2^N)` space taken by the result
   - The dominating auxillary space is taken by the subset built in each step, which takes at most `N` elements.

## Examples

### Example 1

> **Input**: nums = [1,2,3]
>
> **Output**: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

### Example 1

> **Input**: nums = [0]
>
> **Output**: [[],[0]]
