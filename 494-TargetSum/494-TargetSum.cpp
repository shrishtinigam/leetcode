// Last updated: 8/30/2025, 8:18:51 PM

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int range = accumulate(nums.begin(), nums.end(), 0);
        if((target + range)%2 != 0 or abs(target) > range)
            return 0;
        int sum = (target + range) / 2;
        int n = nums.size();
        int dp[n+1][sum+1];

        for(int i = 1; i < sum+1; i++)
            dp[0][i] = 0;
        dp[0][0] = 1;

        for(int i = 1; i < n+1; i++){
            for(int j = 0; j < sum+1; j++){
                if(nums[i-1] > j)
                    dp[i][j] = dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i-1]];
            }
        }

        return dp[n][sum];
    }
};
























/*
int findTargetSumWays(vector<int>& nums, int target) {
        int range = accumulate(nums.begin(), nums.end(), 0);
        if(abs(target) > range or (target + range) % 2 != 0)
            return 0;
        int sum = (range + target) / 2;
        
        int n = nums.size();
        int t[n+1][sum+1];
        for(int i = 0; i < sum + 1; i++)
            t[0][i] = 0;
        t[0][0] = 1;
        
        for(int i = 1; i < n + 1; i++){
            for(int j = 0; j < sum + 1; j++){
                if(nums[i-1] > j)
                    t[i][j] = t[i-1][j];
                else if(nums[i-1] <= j)
                    t[i][j] = t[i-1][j] + t[i-1][j-nums[i-1]];
            }
        }
        return t[n][sum];
    }
*/
/*

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for(int x: nums)
            sum += x;
        if (abs(target) > sum || (sum + target) % 2 != 0){ 
            return 0;
        }
        int s1 = (sum + target)/2;
        int ans = subsetCount(nums,s1);
        return ans;
    }
    
    int subsetCount(vector<int>& nums, int s1){
        int n = nums.size();
        int t[n+1][s1+1];
        t[0][0] = 1;
        for(int i=1;i<s1+1;i++)
            t[0][i] = 0;
        for(int i=1;i<n+1;i++)
            for(int j=0;j<s1+1;j++){
                if(nums[i-1] > j)
                    t[i][j] = t[i-1][j];
                else
                    t[i][j] = t[i-1][j] + t[i-1][j-nums[i-1]];
            }
        for(int i=1;i<n+1;i++)
            for(int j=0;j<s1+1;j++){
                cout << 
            }}
        return t[n][s1];
    }
};*/