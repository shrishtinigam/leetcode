# Last updated: 9/4/2025, 7:57:03 AM
class Solution:
    def heightChecker(self, heights: List[int]) -> int:
        expected = sorted(heights)
        result = 0
        for i in range(len(heights)):
            if heights[i] != expected[i]:
                result += 1
        return result