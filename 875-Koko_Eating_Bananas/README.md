# 875. Koko Eating Bananas

LeetCode Problem Link: <https://leetcode.com/problems/koko-eating-bananas/>

## Description

Koko loves to eat bananas. There are `n` piles of bananas, the `i`th pile has `piles[i]` bananas. The guards have gone and will come back in `h` hours.

Koko can decide her bananas-per-hour eating speed of `k`. Each hour, she chooses some pile of bananas and eats `k` bananas from that pile. If the pile has less than `k` bananas, she eats all of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return *the minimum integer `k` such that she can eat all the bananas within `h` hours*.

## Constraints

- `1 <= piles.length <= 10^4`
- `piles.length <= h <= 10^9`
- `1 <= piles[i] <= 10^9`

## Solution Thoughts

### Observations

- Assuming `n = piles.length` and `m = max(piles)`:
   - Brute force starting from `h=1` to the answer costs `O(nm)`.
- The values `h` in this problem has the following pattern:
   - If Koko finishes using `h0`, all values `h > h0` would also work.
   - If `h0` doesn't work, all values `h < h0` would also NOT work.
- Therefore there exists a threshold `h1` such that:
   - For all `h < h1`, Koko cannot finish all the bananas.
   - For all `h >= h1`, Koko can finish.
- This reminds us the binary search algorithm, which would provide us `O(n log(m))` time complexity.

### Logic

### Complexities

- **Time Complexity** = `O(n log(m))`
   - Binary search takes `O(log(m))` to search for values in `[0, m]`.
   - Each check taken `O(n)` time to complete as one needs to traverse the whole `pile` every time in principle.

- **Space Complexity** = `O(1)`
   - We only store an eating speed `mid` and the total number of hours `total` for Koko to finish, which consumes constant memory.

## Examples

### Example 1

> **Input**: piles = [3,6,7,11], h = 8
>
> **Output**: 4

### Example 2

> **Input**: piles = [30,11,23,4,20], h = 5
>
> **Output**: 30

### Example 3

> **Input**: piles = [30,11,23,4,20], h = 6
>
> **Output**: 23
