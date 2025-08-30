// Last updated: 8/30/2025, 8:21:11 PM
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == nums[i-1])
                k++;
            else
                nums[i-k] = nums[i];
        }
        return nums.size()-k;
    }
};