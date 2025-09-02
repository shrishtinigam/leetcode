# Last updated: 9/2/2025, 9:57:21 AM
class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        n = len(nums)
        _sum = int(n * (n + 1)/2)
        for num in nums:
            _sum -= num
        return _sum