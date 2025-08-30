// Last updated: 8/30/2025, 8:19:35 PM
class Solution {
public:
    /* RECURSIVE */
    /*int rob(vector<int>& nums) {
        return rob(nums, nums.size()-1);
    }
    int rob(vector <int>& nums, int i){
        if(i < 0){
            return 0;
        }
        return max(rob(nums, i - 2) + nums[i], rob(nums, i - 1));
    }*/

    /* TOP DOWN */
    /*
    int rob(vector<int>& nums) {
        vector <int> memo (nums.size(), -1);
        return rob(nums, nums.size()-1, memo);
    }

    int rob(vector <int>& nums, int i, vector<int>& memo){
        if(i < 0)
            return 0;
        if(memo[i] != -1)
            return memo[i];
        memo[i] = max(rob(nums, i - 2, memo) + nums[i], rob(nums, i - 1, memo));
        return memo[i];
    }*/

    /* BOTTOM UP */
    /* int rob(vector<int>& nums){
        vector<int> memo (nums.size() + 1, 0);
        memo[1] = nums[0];

        for(int i = 1; i < nums.size(); i++){
            memo[i + 1] = max(memo[i], memo[i - 1] + nums[i]);
        }

        return memo[nums.size()];
    }*/

    /* OPTIMIZED BOTTOM UP */
    int rob(vector<int>& nums){
        if (nums.size() == 0) 
            return 0;
        int prev1 = 0;
        int prev2 = 0;
        for(int i = 0; i < nums.size(); i++){
            int temp = prev1; 
            prev1 = max(prev1, prev2 + nums[i]);
            prev2 = temp;
        }

        return prev1;
    }

};