# Last updated: 8/30/2025, 8:21:51 PM
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hash_map = {}
        for i in range(len(nums)):
            hash_map[nums[i]] = i
        for i in range(len(nums)):
            complement = target - nums[i]
            if complement in hash_map and hash_map[complement] != i:
                return [i, hash_map[complement]]
        # If no valid pair is found, return an empty list
        return []