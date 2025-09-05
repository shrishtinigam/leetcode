# Last updated: 9/5/2025, 10:37:24 PM
class Solution:
    def findContentChildren(self, g: List[int], s: List[int]) -> int:
        g.sort()
        s.sort()
        i = j = 0

        while i < len(s) and j < len(g):
            if g[j] <= s[i]:
                j += 1
            i += 1

        return j                