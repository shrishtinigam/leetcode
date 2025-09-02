# Last updated: 9/2/2025, 9:57:43 AM
class Solution:
    def findDisappearedNumbersOld(self, nums: List[int]) -> List[int]:
        ideal = set(range(1, len(nums) + 1))
        nums = set(nums)
        left = list(ideal - nums)
        return left
    
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        dp = [0] * (len(nums) + 1)
        result = []
        for num in nums:
            dp[num] = 1
        for i in range(1, len(dp)):
            if dp[i] == 0:
                result.append(i)
        return result