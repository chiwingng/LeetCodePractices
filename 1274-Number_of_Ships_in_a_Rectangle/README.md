# 1274. Number of Ships in a Rectangle

LeetCode Problem Link: <https://leetcode.com/problems/number-of-ships-in-a-rectangle/>

## Description

*This problem is an interactive problem.*

Each ship is located at an integer point on the sea represented by a cartesian plane, and each integer point may contain at most 1 ship.

You have a function `Sea.hasShips(topRight, bottomLeft)` which takes two points as arguments and returns `true` if there is at least one ship in the rectangle represented by the two points, including on the boundary.

Given two points: the top right and bottom left corners of a rectangle, return the number of ships present in that rectangle. It is guaranteed that there are **at most 10 ships** in that rectangle.

Submissions making **more than 400 calls** to `hasShips` will be judged *Wrong Answer*. Also, any solutions that attempt to circumvent the judge will result in disqualification.

## Constraints

- On the input `ships` is only given to initialize the map internally. You must solve this problem "blindfolded". In other words, you must find the answer using the given `hasShips` API, without knowing the `ships` position.
- `0 <= bottomLeft[0] <= topRight[0] <= 1000`
- `0 <= bottomLeft[1] <= topRight[1] <= 1000`
- `topRight != bottomLeft`

## Solution Thoughts

### Observations

- There are `1000 * 1000 = 10^6` points in the map. If we bisect the map in each axis in each iteration, We need to perform `log_4(10^6) = 10` iterations to get to every point.
- We are guaranteed that there are at most 10 ships in the map, that means most of the `hasShips` call will return 0, which we can truncate the subsequent iterations.
   - Given the condition, we have in the worst case `4 * 10 * 10 = 400` calls to `hasShips`:
      - Each level has at most 10 ships to split into further 4 sub-rectangles, so the next level will call at most 40 times `hasShips`
      - There are at most 10 levels, which multiplies to at most 400 calls, which is exactly the constraint given.

### Logic

- In each call of `countShips`:
   - We first check if the coordinates of rectangle is valid: bottomLeft is at bottom-left of topRight. If not we return 0.
   - We truncate the expansion if the current rectangle contains no ships, return 0.
   - If it has ships, at the same time `topRight == bottomLeft`, a ship is located exactly at that point, return 1.
   - For the remaining case, we split the rectangle into 4 equal pieces and return the sum of 4 `countShips` calls for each quadrant.

### Complexities

Let X be the range of x-coordinates and Y be the range of y-coordinates, S be the number of ships in the sea.

- **Time Complexity** = `O(S*(log(max(X,Y)) - 1/2 log S)`
   - Each `countShips` call takes `O(1)` time, so total time complexity is the number of calls to `countShips`.
   - Worst case is having `S = 10` ships scattering evenly in the rectangle that there are `S` regions that each contain 1 ship. (After `S` recursive calls, which corresponds to `log_4 S` round of recursions)
      - Each of such `S` regions will result in 4 calls to `countShips`, then 3 of them truncated and the remaining one splits again into 4.
      - The maximum depth of recursion is `log_2(max(X,Y))` since in each split we divide the two dimensions into half.
   - Therefore the total time complexity is `O(S * (log_2 max(X,Y) - log_4 S)) = O(S * (log max(X,Y) - 1/2 log S))`.

- **Space Complexity** = `O(log_2 max(X,Y))`
   - Each call to `countShips` takes constant space except for the callstack.
   - The maximum depth of recursion is `O(log_2 max(X,Y))`

## Examples

### Example 1

> **Input**: ships = [[1,1],[2,2],[3,3],[5,5]], topRight = [4,4], bottomLeft = [0,0]
>
> **Output**: 3
>
> **Explanation**: From [0,0] to [4,4] we can count 3 ships within the range.

### Example 2

> **Input**: ships = [[1,1],[2,2],[3,3]], topRight = [1000,1000], bottomLeft = [0,0]
>
> **Output**: 3
