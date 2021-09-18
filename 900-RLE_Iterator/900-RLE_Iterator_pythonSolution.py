class RLEIterator(object):

    def __init__(self, encoding):
        """
        :type encoding: List[int]
        """
        self.vec = encoding
        self.index = 0

    def next(self, n):
        """
        :type n: int
        :rtype: int
        """
        while self.index < len(self.vec):
            
            if n <= self.vec[self.index]:
                self.vec[self.index] -= n
                return self.vec[self.index + 1]
            n -= self.vec[self.index]
            self.index += 2
            
        return -1


# Your RLEIterator object will be instantiated and called as such:
# obj = RLEIterator(encoding)
# param_1 = obj.next(n)
