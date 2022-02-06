# 1041. Robot Bounded In Circle

LeetCode Problem Link: <https://leetcode.com/problems/robot-bounded-in-circle/>

## Description

On an infinite plane, a robot initially stands at (0, 0) and faces north. Note that:

- The north direction is the positive direction of the y-axis.
- The south direction is the negative direction of the y-axis.
- The east direction is the positive direction of the x-axis.
- The west direction is the negative direction of the x-axis.

The robot can receive one of three instructions:

- "G": go straight 1 unit.
- "L": turn 90 degrees to the left (i.e., anti-clockwise direction).
- "R": turn 90 degrees to the right (i.e., clockwise direction).

The robot performs the instructions given in order, and repeats them forever.

Return `true` if and only if there exists a circle in the plane such that the robot never leaves the circle.

## Constraints

- `1 <= instructions.length <= 100`
- `instructions[i]` is 'G', 'L' or, 'R'.

## Solution Thoughts

### Observations

- At the end of each cycle of instructions, the robot will end up at a location (x, y) and facing a direction `dir`.
- The displacement can be represented by a vector pointing from the origin (0, 0) to (x, y).
- The direction `dir` means the displacement vector will be rotated in the next round of instructions (either 0, 90 or 180 degrees).
- Since the size of displacement vector does not change in each iteration, if the displacement vector is rotated by non-zero angle, it will form either a square trajectory or a repeating linear trajectory, thus bounded by a circle.
- If the displacement does not rotate, i.e. the robot still faces north after the instructions, the displacement vector will extend itself to infinity and never comes back. UNLESS the size of displacement is zero.

### Logic

- Simulate the robot movement for one iteration, keeping its direction and position.
- Check if it remains at the origin or is not facing North. If so, it is bounded. Otherwise it is not.

## Examples

### Example 1

> **Input**: instructions = "GGLLGG"
>
> **Output**: true
>
> **Explanation**: The robot is initially at (0, 0) facing the north direction.
>
> "G": move one step. Position: (0, 1). Direction: North.
>
> "G": move one step. Position: (0, 2). Direction: North.
>
> "L": turn 90 degrees anti-clockwise. Position: (0, 2). Direction: West.
>
> "L": turn 90 degrees anti-clockwise. Position: (0, 2). Direction: South.
>
> "G": move one step. Position: (0, 1). Direction: South.
>
> "G": move one step. Position: (0, 0). Direction: South.
>
> Repeating the instructions, the robot goes into the cycle: (0, 0) --> (0, 1) --> (0, 2) --> (0, 1) --> (0, 0).
>
> Based on that, we return true.

### Example 2

> **Input**: instructions = "GG"
>
> **Output**: false
>
> **Explanation**: The robot is initially at (0, 0) facing the north direction.
>
> "G": move one step. Position: (0, 1). Direction: North.
>
> "G": move one step. Position: (0, 2). Direction: North.
>
> Repeating the instructions, keeps advancing in the north direction and does not go into cycles.
>
> Based on that, we return false.

### Example 3

> **Input**: instructions = "GL"
>
> **Output**: true
>
> **Explanation**: The robot is initially at (0, 0) facing the north direction.
>
> "G": move one step. Position: (0, 1). Direction: North.
>
> "L": turn 90 degrees anti-clockwise. Position: (0, 1). Direction: West.
>
> "G": move one step. Position: (-1, 1). Direction: West.
>
> "L": turn 90 degrees anti-clockwise. Position: (-1, 1). Direction: South.
>
> "G": move one step. Position: (-1, 0). Direction: South.
>
> "L": turn 90 degrees anti-clockwise. Position: (-1, 0). Direction: East.
>
> "G": move one step. Position: (0, 0). Direction: East.
>
> "L": turn 90 degrees anti-clockwise. Position: (0, 0). Direction: North.
>
> Repeating the instructions, the robot goes into the cycle: (0, 0) --> (0, 1) --> (-1, 1) --> (-1, 0) --> (0, 0).
>
> Based on that, we return true.