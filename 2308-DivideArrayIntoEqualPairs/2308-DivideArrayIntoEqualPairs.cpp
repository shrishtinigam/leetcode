// Last updated: 8/30/2025, 8:18:01 PM
class Solution {
public:
    bool divideArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if(nums.size() % 2 != 0)
            return false;
        for(int i = 0; i < nums.size() - 1; i = i + 2)
        {
            if(nums[i] != nums[i+1])
                return false;
        }
        return true;
    }
};