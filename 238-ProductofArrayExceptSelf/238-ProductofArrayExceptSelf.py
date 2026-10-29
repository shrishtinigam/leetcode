# Last updated: 10/30/2026, 1:23:26 AM
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
15            prefix[i - 1] *= prod
16
17        return prefix
18
19        """
20        
21        n = len(nums)
22        prefix = [1]
23        suffix = [1]
24
25        prod = 1
26        for i in range(n - 1):
27            prod *= nums[i]
28            prefix.append(prod)
29
30        prod = 1
31        for i in range(n - 1, 0, -1):
32            prod *= nums[i]
33            suffix.append(prod)
34
35        suffix.reverse()
36
37        return [prefix[i] * suffix[i] for i in range(n)]"""