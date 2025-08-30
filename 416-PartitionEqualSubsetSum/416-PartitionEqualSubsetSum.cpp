// Last updated: 8/30/2025, 8:19:00 PM
class Solution {
public:
    /* BRUTE FORCE */
    /* 
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2 != 0)
            return false;
        int target = sum/2;
        vector <int> memo (1, 0);
        // this is an easy way to create subsets!
        for(int i = 0; i < nums.size(); i++){
            int curr_size = memo.size();
            for(int j = 0; j < curr_size; j++){
                memo.push_back(memo[j] + nums[i]);
            }
        }
        sort(memo.begin(), memo.end());
        return binary_search(memo.begin(), memo.end(), target);
    }*/

    /* BACKTRACKING AND RECURSION */
/*
    int backtracking(int currSum, int index, vector<int>& nums, int & target){
        if(currSum > target || index >= nums.size())
            return false;
        if(currSum == target)
            return true;
        return backtracking(currSum + nums[index], index + 1, nums, target)||backtracking(currSum,index+1, nums, target);
    }

    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2 != 0)
            return false;
        int target = sum/2;
        cout << target << " ";
        return backtracking(0, 0, nums, target);
    }
*/
    
    /*
    bool subsetSum(vector<int>& nums, int sum, vector <vector<int>> & dp, int i = 0) {
        if(sum == 0)
            return true;
        if(i >= nums.size() || sum < 0)
            return false;
        if(dp[i][sum] != -1)
            return dp[i][sum];
        return dp[i][sum] = subsetSum(nums, sum - nums[i], dp, i + 1) || subsetSum(nums, sum, dp, i + 1);
    }
    bool canPartition(vector<int>& nums) {
        
        int sum = accumulate(nums.begin(), nums.end(), 0);
        vector <vector<int>> dp (nums.size()+1, vector<int> (sum+1, -1));
        if(sum % 2 != 0)
            return false;
        int target = sum/2;
        return subsetSum(nums, target, dp);
        //return true;
    }*/


    /* TOP DOWN
    bool subsetSum(vector<int> &nums, int sum, vector <vector<int>>& dp, int i = 0){
        if(sum == 0)
            return true;

        if(i >= nums.size() || sum < 0)
            return false;
        
        if(dp[i][sum] != -1)
            return dp[i][sum];

        if(nums[i] > sum){
            return dp[i][sum] = subsetSum(nums, sum, dp, i+1);
        }

        return dp[i][sum] = subsetSum(nums, sum - nums[i], dp, i+1) or subsetSum(nums, sum, dp, i+1);
    }


    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        vector <vector<int>> dp (nums.size()+1, vector<int> (sum+1, -1));
        if(sum % 2 != 0)
            return false;
        int target = sum/2;
        return subsetSum(nums, target, dp);
    } */

    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2 != 0)
            return false;
        int target = sum/2;
        int n = nums.size();
        vector <vector<int>> dp (n+1, vector<int> (target+1, 0));
        for(int i = 0; i < n+1; i++){
            dp[i][0] = 1;
        }

        for(int i = 1; i < n+1; i++){
            for(int j = 1; j < target+1; j++){
                if(nums[i-1] > j)
                    dp[i][j] = dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j] or dp[i-1][j-nums[i-1]];
            }
        }

        return dp[n][target];
    }
    
};