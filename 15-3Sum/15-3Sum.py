# Last updated: 10/31/2026, 3:25:00 AM
from bisect import bisect_left, bisect_right

class Solution:
    def threeSum(self, nums):
        counts = {}
        for x in nums:
            counts[x] = counts.get(x, 0) + 1

        res = []
        if counts.get(0, 0) >= 3:
            res.append([0, 0, 0])

        neg = sorted(x for x in counts if x < 0)
        pos = sorted(x for x in counts if x > 0)

        for n in neg:
            lo = bisect_left(pos, (-n + 1) // 2)
            hi = bisect_right(pos, -2 * n)
            for i in range(lo, hi):
                p = pos[i]
                c = -(n + p)
                if c in counts:
                    if c == n:
                        if counts[n] > 1:
                            res.append([n, c, p])
                    elif c == p:
                        if counts[p] > 1:
                            res.append([n, c, p])
                    elif n < c < p:
                        res.append([n, c, p])
        return res
        