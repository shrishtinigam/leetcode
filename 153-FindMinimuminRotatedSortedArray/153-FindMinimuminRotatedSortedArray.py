# Last updated: 10/31/2026, 6:05:27 AM
1class Solution:
2    def findMin(self, nums: list[int]) -> int:
3        
4        hi = len(nums) - 1
5        lo = 0
6       
7        while hi > lo:
8            mid = (hi + lo) // 2
9            if nums[mid] > nums[hi]:
10                lo = mid + 1
11            else:
12                hi = mid
13            
14           
15        return nums[lo]