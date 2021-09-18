class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        counts = collections.Counter(nums1);
        result = []
        
        for n in nums2:
            if counts[n] > 0:
                result.append(n)
                counts[n] -= 1
        
        return result
