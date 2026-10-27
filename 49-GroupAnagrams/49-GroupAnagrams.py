# Last updated: 10/27/2026, 6:43:55 PM
1class Solution:
2
3    def groupAnagrams(self, strs: list[str]) -> list[list[str]]:
4        result = {}
5        
6        for i in (strs):
7            x = tuple(sorted(i))
8            result[x] = result.get(x, []) + [i]
9
10        values = list(result.values())
11        return values