# Last updated: 10/31/2026, 3:03:43 AM
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
11                if _nums[l] + _nums[r] > target:
12                    r -= 1
13                else:
14                    l += 1
15            return result
16        
17        nums.sort()
18        res3sum = set()
19        for i, num in enumerate(nums):
20            target = (-1) * (num)
21            allres = TwoSum(nums, target, i)
22            if allres:
23                for res in allres: 
24                    triplet = [nums[res[0]], nums[res[1]], num]
25                    triplet.sort()
26                    triplet = tuple(triplet)
27                    if triplet not in res3sum:
28                        res3sum.add(triplet)
29        return [list(t) for t in res3sum]