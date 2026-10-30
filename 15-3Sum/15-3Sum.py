# Last updated: 10/31/2026, 3:11:23 AM
1class Solution:
2    def threeSum(self, nums: list[int]) -> list[list[int]]:
3        def TwoSum(_nums, target, start):
4            l = start + 1
5            r = len(_nums) - 1
6            result = []
7
8            while l < r:
9                total = _nums[l] + _nums[r]
10
11                if total == target:
12                    result.append([_nums[l], _nums[r]])
13                    l += 1
14                    r -= 1
15
16                    while l < r and _nums[l] == _nums[l - 1]:
17                        l += 1
18                    while l < r and _nums[r] == _nums[r + 1]:
19                        r -= 1
20
21                elif total > target:
22                    r -= 1
23                else:
24                    l += 1
25
26            return result
27
28        nums.sort()
29        res3sum = []
30
31        for i, num in enumerate(nums):
32            if num > 0:
33                break
34
35            if i > 0 and num == nums[i - 1]:
36                continue
37
38            target = -num
39            allres = TwoSum(nums, target, i)
40
41            for res in allres:
42                res3sum.append([num, res[0], res[1]])
43
44        return res3sum