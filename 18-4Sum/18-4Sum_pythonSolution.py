class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        result = []
        # check if nums has at least 4 elements
        if len(nums) > 3:
            # sort nums
            nums.sort()
            # call kSum with k = 4 and with the whole nums array
            result = self.kSum(nums, 0, 4, target)
        return result;

    def kSum(self, nums: List[int], start: int, k: int, target: int) -> List[List[int]]:
        result = []
        if sum(nums[start:start+k]) > target or sum(nums[-k:]) < target:
            # The smallest k elements has larger sum or largest k elements has smaller sum, no valid result!
            return result
        elif k == 2:
            # This is the two sum case with sorted input
            return self.twoSum(nums, start, target)
        else:
            # loop over all elements except for the last k ones
            for i in range(start, len(nums) - k + 1):
                # check for duplicates
                if i == start or nums[i] != nums[i-1]:
                    # call one k smaller for target - nums[i] and append nums[i] to every solution we get
                    for res in self.kSum(nums, i+1, k-1, target - nums[i]):
                        res.append(nums[i])
                        result.append(res)
            return result
        
    def twoSum(self, nums: List[int], start: int, target: int) -> List[List[int]]:
        low = start
        high = len(nums) - 1
        result = []
        while low < high:
            mysum = nums[low] + nums[high]
            if mysum < target:
                # if the sum is smaller than target, need to increase low
                low += 1
            elif mysum > target:
                high -= 1
            else:
                result.append([nums[low], nums[high]])
                low += 1
                while low < high and nums[low] == nums[low-1]:
                    low += 1
                high -= 1
                while low < high and nums[high] == nums[high+1]:
                    high -= 1
        return result
