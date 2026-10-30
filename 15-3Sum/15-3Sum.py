# Last updated: 10/31/2026, 3:05:13 AM
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
11                elif _nums[l] + _nums[r] > target:
12                    r -= 1
13                else:
14                    l += 1
15            return result
16        
17        nums.sort()
18        res3sum = set()
19        for i, num in enumerate(nums):
20            if i > 0 and num == nums[i - 1]:
21                continue
22            target = (-1) * (num)
23            allres = TwoSum(nums, target, i)
24            if allres:
25                for res in allres: 
26                    triplet = [nums[res[0]], nums[res[1]], num]
27                    triplet.sort()
28                    triplet = tuple(triplet)
29                    if triplet not in res3sum:
30                        res3sum.add(triplet)
31        return [list(t) for t in res3sum]