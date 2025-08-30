// Last updated: 8/30/2025, 8:17:48 PM
class Solution {
public:
    int findMaxK(vector<int>& nums) {
        if(nums.size() == 0 || nums.size() == 1)
            return -1;
        sort(nums.begin(), nums.end());
        int i = 0;
        int j = nums.size()-1;
        
        while(i <= nums.size() - 1){
            if(nums[i] > 0)
                return -1;
            if(nums[j] == abs(nums[i]))
                return nums[j];
            if(nums[j] < abs(nums[i]))
                i++;
            if(nums[j] > abs(nums[i]))
                j--;  
        }
        
        return -1;
    }
};