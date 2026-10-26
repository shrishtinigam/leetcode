# Last updated: 10/26/2026, 8:30:06 PM
1class Solution:
2    def twoSum(self, nums: list[int], target: int) -> list[int]:
3        index_map = {num: i for i, num in enumerate(nums)}
4        for ind, i in enumerate(nums):
5            leftover = target - i
6            if leftover in index_map and ind != index_map[leftover]:
7                return [ind, index_map[leftover]]