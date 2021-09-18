class Solution(object):
    def hIndex(self, citations):
        """
        :type citations: List[int]
        :rtype: int
        """
        n = len(citations)
        left, right = 0, n-1
        
        while left <= right:
            mid = left + (right - left)//2
            cites = n - mid
            if citations[mid] == cites:
                return cites
            if citations[mid] < cites:
                left = mid + 1
            else:
                right = mid - 1
        
        return n - left
