# Last updated: 9/3/2025, 11:01:10 AM
class Solution:
    def thirdMax(self, nums: List[int]) -> int:
        nums = sorted(list(set(nums)))
        nums.reverse()
        nums = nums[:3]
        return nums[-1] if len(nums) == 3 else nums[0]