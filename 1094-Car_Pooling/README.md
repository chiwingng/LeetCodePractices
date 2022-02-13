# 1094. Car Pooling

LeetCode Problem Link: <https://leetcode.com/problems/car-pooling/>

## Description

There is a car with `capacity` empty seats. The vehicle only drives east (i.e., it cannot turn around and drive west).

You are given the integer `capacity` and an array `trips` where `trips[i] = [numPassengers_i, from_i, to_i]` indicates that the `i`-th trip has `numPassengers_i` passengers and the locations to pick them up and drop them off are `from_i` and `to_i` respectively. The locations are given as the number of kilometers due east from the car's initial location.

Return `true` *if it is possible to pick up and drop off all passengers for all the given trips, or `false` otherwise*.

## Solution Thoughts

### Observations

- A simulation of the process can tell the result.
   - First record the number of passengers hopping on or off at each stop.
   - Go through each stop and accumulate the number of passengers on the vehicle.
   - If the number of passengers on the vehicle exceeds `capacity` at any stop, it is not possible to pick up all passengers, return `false`.
   - If the vehicle gets to the last stop without exceeding `capacity`, return `true`.

### Complexities

- **Time Complexity**:
   - It takes `O(N)` time to traverse through `trips`, with each operation taking `O(log(N))` for ordered maps (or `O(1)` for hash maps).
   - If hash map is used, it takes `O(N log(N))` time to sort the map.
   - It takes `O(N)` time to traverse through all stops to simulate the process.
   - So overall the time complexity is `O(N log(N))`.

- **Space Complexity**:
   - `O(N)` space is needed for the map, O(1) space for `n_passengers` variable. Total is `O(N)`.

## Constraints

- `1 <= trips.length <= 1000`
- `trips[i].length == 3`
- `1 <= numPassengers_i <= 100`
- `0 <= from_i < to_i <= 1000`
- `1 <= capacity <= 10^5`

## Examples

### Example 1

> **Input**: trips = [[2,1,5],[3,3,7]], capacity = 4
>
> **Output**: false

### Example 2

> **Input**: trips = [[2,1,5],[3,3,7]], capacity = 5
>
> **Output**: true