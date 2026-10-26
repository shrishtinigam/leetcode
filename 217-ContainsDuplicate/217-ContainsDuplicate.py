# Last updated: 10/26/2026, 7:39:08 PM
1class Solution:
2    def containsDuplicate(self, nums: list[int]) -> bool:
3        """nums.sort()
4        for i in range(1, len(nums)):
5            if nums[i] == nums[i-1]:
6                return True
7        return False"""
8
9        """ memory limit exceeded
10        arr = [0] * (10**9)
11        arr_neg = [0] * (10**9)
12
13        for i in nums:
14            if i >= 0: 
15                arr[i] = arr[i] + 1
16                if arr[i] > 1:
17                    return True
18            if i < 0: 
19                i = i * (-1)
20                arr_neg[i] = arr_neg[i] + 1
21                if arr_neg[i] > 1:
22                    return True
23        return False
24        """
25        """
26        my_set = set()
27        for i in nums:
28            if i in my_set:
29                return True
30            else:
31                my_set.add(i)
32        return False"""
33
34        my_set = set(nums)
35
36        return True if len(my_set) < len(nums) else False