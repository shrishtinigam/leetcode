# Last updated: 10/26/2026, 8:32:03 PM
1class Solution:
2    def twoSum(self, nums: list[int], target: int) -> list[int]:
3        """index_map = {num: i for i, num in enumerate(nums)}
4        for ind, i in enumerate(nums):
5            leftover = target - i
6            if leftover in index_map and ind != index_map[leftover]:
7                return [ind, index_map[leftover]]"""
8        index_map = {}
9
10        for i, num in enumerate(nums):
11            leftover = target - num
12
13            if leftover in index_map:
14                return [index_map[leftover], i]
15
16            index_map[num] = i