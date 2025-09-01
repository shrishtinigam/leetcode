# Last updated: 9/1/2025, 8:13:18 PM
class Solution:
    def summaryRanges(self, nums: List[int]) -> List[str]:
        summary_ranges = []
        if len(nums) == 1:
            return [f"{nums[0]}"]
        if len(nums) == 0:
            return []
        cur_a, cur_b = nums[0], nums[0]
        for i in range(len(nums)):
            if i != len(nums) - 1 and nums[i] + 1 == nums[i+1]:
                cur_b = nums[i+1]
            else:
                if cur_a == cur_b:
                    summary_ranges += [f"{cur_a}"]
                else:
                    summary_ranges += [f"{cur_a}->{cur_b}"]
                if i != len(nums) - 1:
                    cur_a, cur_b = nums[i+1], nums[i+1]
        return summary_ranges
