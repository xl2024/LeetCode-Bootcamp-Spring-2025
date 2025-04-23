class Solution(object):
    def coinChange(self, coins, amount):
        """
        :type coins: List[int]
        :type amount: int
        :rtype: int
        """
        amts = [0]
        for i in range(1, amount+1):
            mincnt = float('inf')
            for coin in coins:
                if i >= coin and amts[i-coin] != -1 and amts[i-coin] + 1 < mincnt:
                    mincnt = amts[i-coin] + 1
            amts.append(-1 if mincnt == float('inf') else mincnt)
        return amts[-1]