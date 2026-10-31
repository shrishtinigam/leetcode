# Last updated: 10/31/2026, 7:01:14 AM
1class Solution:
2    def characterReplacement(self, s: str, k: int) -> int:
3        l = 0
4        r = 0
5        freq_map = {}
6        maxlen = 0
7        while r < len(s):
8            freq_map[s[r]] = freq_map.get(s[r], 0) + 1
9            replacements = (r - l + 1) - max(freq_map.values())
10            if replacements <= k:
11                maxlen = max(maxlen, r - l + 1)
12            else:
13                freq_map[s[l]] -= 1
14                l += 1
15            r += 1
16        return maxlen
17
18