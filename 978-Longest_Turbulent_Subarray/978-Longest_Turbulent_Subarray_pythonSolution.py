class Solution(object):
    def maxTurbulenceSize(self, arr):
        """
        :type arr: List[int]
        :rtype: int
        """
        n_nums = len(arr)
        if (n_nums < 2):
            return n_nums
        
        result = (arr[0] != arr[1]) + 1
        up, down = 1, 1
        
        for i in range(1, n_nums):
            if arr[i] > arr[i-1]:
                up = down + 1
                down = 1
                result = max(result, up)
            elif arr[i] < arr[i-1]:
                down = up + 1
                up = 1
                result = max(result, down)
            else:
                up, down = 1, 1
        
        return result
