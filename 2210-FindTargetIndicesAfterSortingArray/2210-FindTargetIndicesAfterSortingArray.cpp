// Last updated: 8/30/2025, 8:18:06 PM
class Solution {
public:
    
    vector<int> targetIndices(vector<int>& nums, int target) {

        sort(nums.begin(), nums.end());
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == target)
                ans.push_back(i);
        }
        return ans;
    }
};