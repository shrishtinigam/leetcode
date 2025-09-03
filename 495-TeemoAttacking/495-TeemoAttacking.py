# Last updated: 9/3/2025, 11:10:32 AM
class Solution:
    def findPoisonedDuration(self, timeSeries: List[int], duration: int) -> int:
        time = 0
        for i in range(1, len(timeSeries)):
            time += min(duration, timeSeries[i] - timeSeries[i-1])
        
        time += duration
        return time
            