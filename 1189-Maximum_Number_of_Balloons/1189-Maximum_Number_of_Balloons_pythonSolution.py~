class Solution:
    def maxNumberOfBalloons(self, text: str) -> int:
        counts = collections.Counter(text)
        pattern = collections.Counter("balloon")
        return min(counts[c]//pattern[c] for c in pattern)
