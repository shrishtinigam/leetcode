# Last updated: 9/1/2025, 8:01:58 PM
class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        return len(nums)!=len(set(nums))