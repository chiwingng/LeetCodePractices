class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        # a map from num value to index
        indices = {};
        # loop over numbers
        for i, n in enumerate(nums):
            desired = target - n
            # search if desired difference is seen before
            if desired in indices.keys():
                # return if seen before
                return [i, indices[desired]]
            else:
                # insert current value into seen dict
                indices[n] = i
                
        return [-1, -1]
