# Last updated: 10/28/2026, 3:41:43 AM
1class Solution:
2    def maxSubArray(self, nums: list[int]) -> int:
3        maxp = nums[0]
4        cur_sum = 0
5        for i in nums:
6            if cur_sum < 0:
7                cur_sum = 0
8            cur_sum += i
9            maxp = max(cur_sum, maxp)
10        return maxp