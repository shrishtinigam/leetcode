# Last updated: 10/31/2026, 5:05:04 AM
1class Solution:
2    def maxArea(self, height: list[int]) -> int:
3        l = 0
4        r = len(height) - 1
5        curmax = 0
6        cur = 0
7        while (l < r):
8            cur = (r - l) * min (height[r], height[l])
9            curmax = max(cur, curmax)
10            if height[r] >= height[l]:
11                l += 1
12            else:
13                r -= 1
14
15        return curmax
16        """
17        amax = 0
18        for i in range(len(height)):
19            l = i
20            r = len(height) - 1
21            curmax = 0
22            cur = 0
23            while (l < r):
24                cur = (r - l) * min (height[r], height[l])
25                curmax = max(cur, curmax)
26                r -= 1
27            amax = max(curmax, amax)
28        return amax
29        """