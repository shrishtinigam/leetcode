// Last updated: 8/30/2025, 8:19:13 PM
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow(0), fast(0);
        while(true)
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if(slow == fast)
                break;
        }
        fast = 0;
        while(slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};






















/*
int n = nums.size() - 1;
        n = (n*(n+1))/2;
        int x = 0;
        x = accumulate(nums.begin(), nums.end(), 0);
        return x-n;
*/