# Last updated: 10/28/2026, 3:37:21 AM
1class Solution:
2    def maxSubArray(self, nums: list[int]) -> int:
3        l, r = 0, 0
4        maxp = nums[0]
5        cur_sum = nums[0] 
6        for i in range(len(nums) - 1):
7            if cur_sum < 0:
8                cur_sum = 0
9            r = r + 1
10            cur_sum = cur_sum + nums[r]
11            if cur_sum > maxp:
12                maxp = cur_sum
13            elif cur_sum < 0:
14                l = r
15        return maxp