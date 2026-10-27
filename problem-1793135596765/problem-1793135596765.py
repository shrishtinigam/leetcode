# Last updated: 10/28/2026, 2:43:16 AM
1class Solution:
2    def maxProfit(self, prices: list[int]) -> int:
3        buy_price = prices[0]
4        profit = 0
5
6        for p in prices[1:]:
7            if buy_price > p:
8                buy_price = p
9            
10            profit = max(profit, p - buy_price)
11        
12        return profit
13        
14        """
15        l, r = 0, 1
16        maxp = 0
17        for i in range(len(prices) - 1):
18            if prices[l] > prices[r]:
19                l = r
20            else:
21                maxp = max(maxp, prices[r] - prices[l])
22            r = r + 1
23        return maxp"""
24