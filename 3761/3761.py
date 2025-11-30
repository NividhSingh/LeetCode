class Solution(object):
    def minMirrorPairDistance(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        d = {}
        m = -1
        nums = nums[::-1]
        for i, num in enumerate(nums):
            opposite = int(str(num)[::-1])
            print(opposite)
            if opposite in d:
                distance = i - d[opposite]
                if (m == -1 or distance < m):
                    m = distance
            d[num] = i
        return m
