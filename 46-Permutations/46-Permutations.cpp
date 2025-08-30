// Last updated: 8/30/2025, 8:20:55 PM
class Solution {
public:
    vector<vector<int>> res;
    int n;
    void helper(vector<int>& nums, int idx){
        if(idx == n){
            res.push_back(nums);
            return;
        }
        for(int i = idx; i < n; i++){
            swap(nums[idx], nums[i]);
            helper(nums, idx+1);
            swap(nums[idx], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        helper(nums, 0);
        return res;
    }
};