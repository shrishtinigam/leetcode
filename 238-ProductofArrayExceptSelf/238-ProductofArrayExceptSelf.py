# Last updated: 10/30/2026, 1:25:22 AM
class Solution:
    def productExceptSelf(self, nums: list[int]) -> list[int]:
        n = len(nums)
        prod = 1
        zero_counter = 0
        for v in nums:
            if v != 0: prod *= v
            else: zero_counter += 1
        
        if zero_counter > 1: return [0 for _ in range(n)]
        elif zero_counter == 0:
            return [prod//v for v in nums]
        else:
            return [0 if v != 0 else prod for v in nums]