# Last updated: 10/31/2026, 3:09:31 AM
1class Solution:
2    def threeSum(self, nums: list[int]) -> list[list[int]]:
3        def TwoSum(_nums, target, start):
4            l = start + 1
5            r = len(_nums) - 1
6            result = []
7            while l < r:
8                if _nums[l] + _nums[r] == target:
9                    result.append([l, r])
10                    l += 1
11                    r -= 1
12                elif _nums[l] + _nums[r] > target:
13                    r -= 1
14                else:
15                    l += 1
16
17                """while l < r and l > 0 and _nums[l] == _nums[l - 1]:
18                    l += 1
19
20                if r < len(_nums) - 1:
21                    while l < r and _nums[r] == _nums[r + 1]:
22                        r -= 1"""
23            return result
24        
25        nums.sort()
26        res3sum = set()
27        for i, num in enumerate(nums):
28            if i > 0 and num == nums[i - 1]:
29                continue
30            target = (-1) * (num)
31            allres = TwoSum(nums, target, i)
32            if allres:
33                for res in allres: 
34                    triplet = [nums[res[0]], nums[res[1]], num]
35                    triplet.sort()
36                    triplet = tuple(triplet)
37                    if triplet not in res3sum:
38                        res3sum.add(triplet)
39        return [list(t) for t in res3sum]