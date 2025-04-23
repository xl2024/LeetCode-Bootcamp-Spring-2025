class Solution(object):
    def canPartition(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        sums = {0}
        target = sum(nums)
        if target % 2 == 1:
            return False
        else:
            target = target // 2
        for num in nums:
            if target - num in sums:
                return True
            newsums = set()
            for s in sums:
                if s + num < target:
                    newsums.add(s + num)
            sums = sums.union(newsums)
        return False