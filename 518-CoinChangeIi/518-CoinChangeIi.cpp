// Last updated: 8/30/2025, 8:18:48 PM
class Solution {
public:
    int change(int sum, vector<int>& coins) {
        int n = coins.size();

        int dp[n+1][sum+1];

        for(int i = 0; i < n+1; i++){
            for(int j = 0; j < sum+1; j++){
                if(j == 0)
                    dp[i][j] = 1;
                else if(i == 0 and j != 0)
                    dp[i][j] = 0;
            }
        }

        for(int i = 1; i < n+1; i++){
            for(int j = 1; j < sum+1; j++){
                if(coins[i-1] > j){
                    dp[i][j] = dp[i-1][j];
                }else{
                    dp[i][j] = dp[i-1][j] + dp[i][j-coins[i-1]];
                }
            }
        }

        return dp[n][sum];
    }
};