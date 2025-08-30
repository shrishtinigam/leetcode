# Last updated: 8/30/2025, 8:20:06 PM
class Solution(object):
    def minimumTotal(self, t):
        return reduce(lambda a,b:[f+min(d,e)for d,e,f in zip(a,a[1:],b)],t[::-1])[0]
        