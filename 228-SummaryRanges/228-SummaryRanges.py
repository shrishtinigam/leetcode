# Last updated: 9/1/2025, 8:19:11 PM
class Solution:
    def summaryRanges(self, nums: List[int]) -> List[str]:
        if not nums:
            return []
        ranges = []
        start = prev = nums[0]
        for num in nums[1:]:
            if num == prev + 1:  # continue the range
                prev = num
            else:
                ranges.append(str(start) if start == prev else f"{start}->{prev}")
                start = prev = num
        ranges.append(str(start) if start == prev else f"{start}->{prev}")
        return ranges
