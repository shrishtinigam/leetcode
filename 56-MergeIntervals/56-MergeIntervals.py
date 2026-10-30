# Last updated: 10/31/2026, 4:04:42 AM
1class Solution:
2    def merge(self, intervals: list[list[int]]) -> list[list[int]]:
3        i = 0
4        intervals.sort(key=lambda x: x[0])
5        while i < (len(intervals)) - 1:
6            if intervals[i][1] >= intervals[i + 1][0]:
7                intervals[i][1] = max(intervals[i][1], intervals[i + 1][1])
8                intervals.pop(i + 1)
9            else:
10                i += 1
11        return intervals