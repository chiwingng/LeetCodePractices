class Solution:
    def trap(self, height: List[int]) -> int:
        n_bars = len(height)
        left, right, trapped = 0, n_bars - 1, 0
        lmax, rmax = 0, 0
        while left < right:
            if height[left] < height[right]:
                lmax = max(lmax, height[left])
                trapped += (lmax - height[left])
                left += 1
            else:
                rmax = max(rmax, height[right])
                trapped += (rmax - height[right])
                right -= 1
        return trapped
