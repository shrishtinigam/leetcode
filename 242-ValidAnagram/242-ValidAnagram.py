# Last updated: 10/26/2026, 7:51:02 PM
1class Solution:
2    def isAnagram(self, s: str, t: str) -> bool:
3        s_map, t_map = {}, {}
4        for char in s:
5            s_map[char] = s_map.get(char, 0) + 1
6
7        for char in t:
8            t_map[char] = t_map.get(char, 0) + 1
9
10        return s_map == t_map