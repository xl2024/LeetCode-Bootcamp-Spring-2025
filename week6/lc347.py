class Solution(object):
    def topKFrequent(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        freq = {}
        for num in nums:
            if num in freq:
                freq[num] += 1
            else:
                freq[num] = 1
        slist = [[] for i in range(len(nums)+1)]
        for num in freq:
            slist[freq[num]].append(num)
        ans = []
        for i in range(len(nums), 0, -1):
            if len(slist[i]) > 0:
                for num in slist[i]:
                    if len(ans) < k:
                        ans.append(num)
        return ans