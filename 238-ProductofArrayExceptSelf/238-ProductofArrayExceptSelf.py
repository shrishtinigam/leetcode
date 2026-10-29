# Last updated: 10/30/2026, 1:18:53 AM
1class Solution:
2    def productExceptSelf(self, nums: list[int]) -> list[int]:
3        n = len(nums)
4        prefix = [1]
5        suffix = [1]
6
7        prod = 1
8        for i in range(n - 1):
9            prod *= nums[i]
10            prefix.append(prod)
11
12        prod = 1
13        for i in range(n - 1, 0, -1):
14            prod *= nums[i]
15            suffix.append(prod)
16
17        suffix.reverse()
18
19        return [prefix[i] * suffix[i] for i in range(n)]