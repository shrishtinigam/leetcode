# Last updated: 10/28/2026, 2:41:04 AM
1class Solution:
2    def maxProfit(self, prices: list[int]) -> int:
3        l, r = 0, 1
4        maxp = 0
5        for i in range(len(prices) - 1):
6            if prices[l] > prices[r]:
7                l = r
8            else:
9                maxp = max(maxp, prices[r] - prices[l])
10            r = r + 1
11        return maxp
12