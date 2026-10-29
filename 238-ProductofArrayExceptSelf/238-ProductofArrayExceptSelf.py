# Last updated: 10/30/2026, 1:18:13 AM
1class Solution:
2    def productExceptSelf(self, nums: list[int]) -> list[int]:
3        prefix = [1]
4        suffix = [1]
5        prod = 1
6        length = len(nums) - 1
7        for v in range(length):
8            prod = prod * nums[v]
9            prefix.append(prod)
10        prod = 1
11        numsr = nums.copy()
12        numsr.reverse()
13        for v in range(length):
14            prod = prod * numsr[v]
15            suffix.append(prod)
16        result = []
17        suffix.reverse() 
18        for i in range(len(nums)):
19            result.append(prefix[i] * suffix[i])
20        return result