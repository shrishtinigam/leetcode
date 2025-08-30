// Last updated: 8/30/2025, 8:19:14 PM
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zeroes = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == 0)
                zeroes++;
            else
                nums[i-zeroes] = nums[i];
        }
        for(int i = nums.size()-zeroes; i < nums.size(); i++)
            nums[i] = 0;
    }
};