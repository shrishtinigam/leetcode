// Last updated: 8/30/2025, 8:18:26 PM
class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int mx = nums[nums.size()-1], mn = nums[0];
        int res = mx - mn;
        for(int i = 1; i < nums.size(); i++){
            mx = max(nums[i-1]+k, nums[nums.size()-1]-k);
            mn = min(nums[i]-k, nums[0]+k);
            res = min(res, mx-mn);
        }
        return res;
    }
};

