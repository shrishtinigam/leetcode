# Last updated: 10/31/2026, 3:53:42 AM
1from bisect import bisect_left, bisect_right
2
3class Solution:
4    def threeSum(self, nums: list[int]) -> list[list[int]]:
5        # creating the frequency map
6        freq = {}
7        for num in nums:
8            freq[num] = freq.get(num, 0) + 1
9
10        result = []
11
12        # edge case: we have 3 occurances of 0 in the list
13        if freq.get(0, 0) >= 3:
14            result.append([0, 0, 0])
15
16        negatives = sorted(x for x in freq if x < 0) # python list of all the unique negatives numbers, sorted
17        positives = sorted(x for x in freq if x > 0) # python list of all the unique positive numbers, sorted
18
19        for n in negatives:
20            # calculating the range for p for any given n
21            left = bisect_left(positives, (-n + 1) // 2)
22            right = bisect_right(positives, -2 * n)
23
24            # looking for valid pairs using complement lookup (similar to Two Sum)
25            for i in range(left, right):
26                p = positives[i]
27                c = -(n + p)
28
29                if c not in freq:
30                    continue
31
32                # handling non-distinct values in triplet case where 2 negative values are same
33                if c == n:
34                    if freq[n] >= 2:
35                        result.append([n, c, p])
36
37                # handling non-distinct values in triplet case where 2 positive values are same
38                elif c == p:
39                    if freq[p] >= 2:
40                        result.append([n, c, p])
41
42                # all three values are distinct
43                elif n < c < p:
44                    result.append([n, c, p])
45
46        return result
47"""class Solution:
48    def threeSum(self, nums: list[int]) -> list[list[int]]:
49        def TwoSum(_nums, target, start):
50            l = start + 1
51            r = len(_nums) - 1
52            result = []
53
54            while l < r:
55                total = _nums[l] + _nums[r]
56
57                if total == target:
58                    result.append([_nums[l], _nums[r]])
59                    l += 1
60                    r -= 1
61
62                    while l < r and _nums[l] == _nums[l - 1]:
63                        l += 1
64                    while l < r and _nums[r] == _nums[r + 1]:
65                        r -= 1
66
67                elif total > target:
68                    r -= 1
69                else:
70                    l += 1
71
72            return result
73
74        nums.sort()
75        res3sum = []
76
77        for i, num in enumerate(nums):
78            if num > 0:
79                break
80
81            if i > 0 and num == nums[i - 1]:
82                continue
83
84            target = -num
85            allres = TwoSum(nums, target, i)
86
87            for res in allres:
88                res3sum.append([num, res[0], res[1]])
89
90        return res3sum
91
92    from bisect import bisect_left, bisect_right
93
94class Solution:
95    def threeSum(self, nums):
96        counts = {}
97        for x in nums:
98            counts[x] = counts.get(x, 0) + 1
99
100        res = []
101        if counts.get(0, 0) >= 3:
102            res.append([0, 0, 0])
103
104        neg = sorted(x for x in counts if x < 0)
105        pos = sorted(x for x in counts if x > 0)
106
107        for n in neg:
108            lo = bisect_left(pos, (-n + 1) // 2)
109            hi = bisect_right(pos, -2 * n)
110            for i in range(lo, hi):
111                p = pos[i]
112                c = -(n + p)
113                if c in counts:
114                    if c == n:
115                        if counts[n] > 1:
116                            res.append([n, c, p])
117                    elif c == p:
118                        if counts[p] > 1:
119                            res.append([n, c, p])
120                    elif n < c < p:
121                        res.append([n, c, p])
122        return res
123"""