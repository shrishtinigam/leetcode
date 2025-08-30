// Last updated: 8/30/2025, 8:20:29 PM
class Solution {
public:

    void backtrack(int ind, vector<int>subset, vector<int>& nums, vector <vector<int>>& res){
        if(ind == nums.size()){
            res.push_back(subset);
            return;
        }
        subset.push_back(nums[ind]);
        backtrack(ind + 1, subset, nums, res);
        subset.pop_back();
        while(ind + 1 < nums.size() and nums[ind] == nums[ind+1]){
            ind+=1;
        }
        backtrack(ind+1, subset, nums, res);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector <vector<int>> res;
        backtrack(0, {}, nums, res);
        return res;
    }
};