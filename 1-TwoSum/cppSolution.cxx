class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // unordered map to store the numbers
        // keys being the number and value being the index in given vector
        unordered_map<int, int> numbers_map;
        for (int i = 0; i < nums.size(); ++i) {
            // return the pair of index if the complement of the current number is already stored
            unordered_map<int, int>::iterator it = numbers_map.find(target - nums[i]);
            if(it != numbers_map.end()) {
                return vector<int> {it->second, i};
            }
            // otherwise store the current number
            else {
                numbers_map[nums[i]] = i;
            }
        }
        return vector<int>{-1, -1};
    }
};
