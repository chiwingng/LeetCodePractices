class Solution:
  def isRobotBounded(self, instructions: str) -> bool:
    # initialize position and direction
    x = y = d = 0;
    directions = [[0,1], [1,0], [0,-1], [-1,0]]
    
    for c in instructions:
      if c is 'L': # turn left, -1 or +3 in direction and mod 4
        d = (d + 3) % 4
      elif c is 'R': # turn right, +1 and mod 4
        d = (d + 1) % 4
      else: # step forward in directions[d]
        x += directions[d][0]
        y += directions[d][1]
    
    # only bounded if robot returns to origin or not facing north after one round
    return (x == 0 and y == 0) or (d != 0)
