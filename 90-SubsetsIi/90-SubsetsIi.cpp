// Last updated: 8/30/2025, 8:20:21 PM
/*class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        vector<vector<int>> ans;       // to store all susbets
        vector<int> curr;         // to store current individual subset (that we will build)
        sort(nums.begin(),nums.end());      // sort the array so that duplicates are adjacent 
        helper(nums,ans,curr,0);       // we start from index 0
        return ans;
        
    }
    
    void helper(vector<int>& nums, vector<vector<int>>& ans, vector<int>& curr, int idx)
    {
        ans.push_back(curr);       // we include current susbet into final ans
        for(int i = idx; i < nums.size(); i++) // check for all possibilites
        {     
            if(i > idx and nums[i] == nums[i-1]) 
                continue;      // if duplicate then we continue
            curr.push_back(nums[i]);     // we include nums[i] in current subset
            helper(nums, ans, curr, i+1); 
            curr.pop_back();         // to get subset without nums[i]
        }
    }  
};*/

class Solution {
public:

    void backtrack(int ind, vector<int>subset, vector<int>& nums, vector <vector<int>>& res){
        if(ind == nums.size()){
            res.push_back(subset);
            //for(int i = 0; i < subset.size(); i++){
            //cout << subset[i] << " ";
            return;
        }
        //cout << "\n";
            
        subset.push_back(nums[ind]);
        backtrack(ind + 1, subset, nums, res);
        subset.pop_back();
        while(ind + 1 < nums.size() and nums[ind] == nums[ind+1]){
            ind+=1;
        }
        backtrack(ind+1, subset, nums, res);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector <vector<int>> res;
        backtrack(0, {}, nums, res);
        return res;
    }
};