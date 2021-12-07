class SnapshotArray {
  vector<map<int, int>> snaps;
  int curr_snap;
public:
  SnapshotArray(int length) : snaps(length), curr_snap(0) {}
    
  void set(int index, int val) {
    snaps[index][curr_snap] = val;
  }
    
  int snap() {
    return curr_snap++;
  }
    
  int get(int index, int snap_id) {
    auto it = snaps[index].upper_bound(snap_id);
    return it == snaps[index].begin() ? 0 : prev(it)->second;
  }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
