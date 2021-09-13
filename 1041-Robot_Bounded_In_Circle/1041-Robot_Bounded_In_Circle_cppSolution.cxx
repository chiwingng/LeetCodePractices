class Solution {
public:
  bool isRobotBounded(string instructions) {
    // initial position and direction (dir = 0,1,2,3 means N,E,S,W)
    int x = 0, y = 0, dir = 0;
    vector< vector<int> > directions = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    
    for (char& c : instructions) {
      if (c == 'L') // turn left, dir needs to -1, equivalent to +3 mod 4
        dir = (dir + 3) % 4;
      else if (c == 'R') // turn right, dir needs to +1, and then mod 4
        dir = (dir + 1) % 4;
      else {
        // move forward along directions[dir]
        x += directions[dir][0];
        y += directions[dir][1];
      }
    }
    // if the robot returned to origin or it is not facing north, it is bounded
    return (!x && !y) || dir;
  }
};
