class Solution(object):
    def minimumTotal(self, t):
        return reduce(lambda a,b:[f+min(d,e)for d,e,f in zip(a,a[1:],b)],t[::-1])[0]
        