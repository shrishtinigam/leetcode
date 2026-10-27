# Last updated: 10/28/2026, 2:53:22 AM
1class Solution:
2    def isValid(self, s: str) -> bool:
3        stk = []
4        f = ['(', '[','{']
5        l = {')':'(', ']':'[', '}':'{'}
6        for i in s:
7            if i in f:
8                stk.append(i)
9            else:
10                if len(stk)==0 or stk[-1] != l[i]:
11                    return False
12                else:
13                    stk.pop()
14        if len(stk) > 0:
15            return False
16        return True