# Last updated: 10/31/2026, 4:07:16 AM
1class Solution:
2    def merge(self, intervals: list[list[int]]) -> list[list[int]]:
3        intervals.sort(key=lambda x: x[0])
4        result = [intervals[0]]
5        i = 1
6
7        while i < len(intervals):
8            if result[-1][1] >= intervals[i][0]:
9                result[-1][1] = max(result[-1][1], intervals[i][1])
10            else:
11                result.append(intervals[i])
12            i += 1
13
14        return result