# Last updated: 9/3/2025, 11:08:56 AM
class Solution:
    def findPoisonedDuration(self, timeSeries: List[int], duration: int) -> int:
        total_duration = 0
        start = timeSeries[0]
        for cur in timeSeries[1:]:
            if start + duration < cur:
                total_duration += duration
            else:
                total_duration += cur - start
            start = cur
        total_duration += duration
        return total_duration
