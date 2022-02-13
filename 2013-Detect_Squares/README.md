# 2013. Detect Squares

LeetCode Problem Link: <https://leetcode.com/problems/detect-squares/>

## Description

You are given a stream of points on the X-Y plane. Design an algorithm that:

- **Adds** new points from the stream into a data structure. **Duplicated** points are allowed and should be treated as different points.
- Given a query point, **counts** the number of ways to choose three points from the data structure such that the three points and the query point form an **axis-aligned square** with **positive** area.

An *axis-aligned square** is a square whose edges are all the same length and are either parallel or perpendicular to the x-axis and y-axis.

Implement the `DetectSquares` class:

- `DetectSquares()` Initializes the object with an empty data structure.
- `void add(int[] point)` Adds a new point `point = [x, y]` to the data structure.
- `int count(int[] point)` Counts the number of ways to form **axis-aligned squares** with point `point = [x, y]` as described above.

## Solution Thoughts

### Observations

- Duplicated points are treated as separate points, so a count for each coordinate is needed.
- For any axis-aligned squares:
   - The "slash" diagonal have the same difference of coordinates (`y-x`).
   - The "back-slash" diagonal have the same sum of coordinates (`y+x`).
- Maintaining two maps of `y-x` to `x` and `y+x` to `x` can tell all pairs of points that lie on the same diagonal.
- Another way is to maintain two maps of `y` to `x` and `x` to `y`. But need to check for the lengths.

### Logic

- For each point added, increment the corresponding count, insert the coordinates into the two maps for diagonals.
- While counting squares:
   - For both maps:
      - Loop over all diagonal coordinates
      - Skip points that are the same as query point
      - Infer the two other coordinates
      - Increase the result by the multiple of number of points on each of three coordinates.

### Complexities

- **Time Complexity**
   - `add(point)`: `O(1)` as we use hash maps and hash sets
   - `count(point)`: `O(N)` where `N` is the total number of points added before the query

- **Space Complexity**
   - `O(XY)` space is needed to store all the counts at each coordinates, where `X` and `Y` are the ranges in each coordinate axes, in this case 1001.

## Constraints

- `point.length == 2`
- `0 <= x, y <= 1000`
- At most `3000` calls **in total** will be made to `add` and `count`.

## Examples

### Example 1

> **Input**
>
> ["DetectSquares", "add", "add", "add", "count", "count", "add", "count"]
>
> [[], [[3, 10]], [[11, 2]], [[3, 2]], [[11, 10]], [[14, 8]], [[11, 2]], [[11, 10]]]
>
> **Output**
>
> [null, null, null, null, 1, 0, null, 2]
>
> 
>
> **Explanation**
>
> DetectSquares detectSquares = new DetectSquares();
>
> detectSquares.add([3, 10]);
>
> detectSquares.add([11, 2]);
>
> detectSquares.add([3, 2]);
>
> detectSquares.count([11, 10]); // return 1. You can choose:
>
>                                //   - The first, second, and third points
>
> detectSquares.count([14, 8]);  // return 0. The query point cannot form a square with any points in the data structure.
>
> detectSquares.add([11, 2]);    // Adding duplicate points is allowed.
>
> detectSquares.count([11, 10]); // return 2. You can choose:
>
>                                //   - The first, second, and third points
>
>                                //   - The first, third, and fourth points