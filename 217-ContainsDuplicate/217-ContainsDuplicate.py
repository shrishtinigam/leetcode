# Last updated: 10/26/2026, 7:23:33 PM
1class Solution:
2    def containsDuplicate(self, nums: list[int]) -> bool:
3        nums.sort()
4        for i in range(1, len(nums)):
5            if nums[i] == nums[i-1]:
6                return True
7        return False