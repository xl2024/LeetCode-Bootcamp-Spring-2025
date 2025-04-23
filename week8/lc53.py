class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        maxsum = 0
        allmax = float('-inf')
        for num in nums:
            maxsum = maxsum + num
            if maxsum > allmax:
                allmax = maxsum
            if maxsum < 0:
                maxsum = 0
        return allmax