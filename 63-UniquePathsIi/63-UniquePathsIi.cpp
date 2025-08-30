// Last updated: 8/30/2025, 8:20:38 PM
class Solution {
public:

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        long r = obstacleGrid.size();
        long c = obstacleGrid[0].size();
        vector<long> dp(c, 0);
        dp[c-1] = 1;
        for(int i = r - 1; i >= 0; i--){
            for(int j = c - 1; j >= 0; j--){
                if(obstacleGrid[i][j])
                    dp[j] = 0;
                else if(j + 1 < c)
                    dp[j] = dp[j] + dp[j+1];
            }
        }

        return dp[0];
    }
































/*
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        long r = obstacleGrid.size();
        long c = obstacleGrid[0].size();
        vector<long> dp(c, 0);
        dp[c-1] = 1;

        for(int i = r - 1; i >= 0; i--){
            for(int j = c - 1; j >= 0; j--){
                if(obstacleGrid[i][j])
                    dp[j] = 0;
                else if(j + 1 < c)
                    dp[j] = dp[j] + dp[j + 1];
                /*else
                    dp[j] = dp[j];
            }   
        }

        return dp[0];
    }*/
    /*************************************************************
    int M, N;
    int recur(vector<vector<int>>& og, int r, int c, vector<vector<int>>& dp){
        if(r == M or c == N or og[r][c])
            return 0;
        if(dp[r][c] >= 1)
            return dp[r][c];
        dp[r][c] = recur(og, r + 1, c, dp) + recur(og, r, c + 1, dp);
        return dp[r][c];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int r = obstacleGrid.size();
        int c = obstacleGrid[0].size();
        M = r;
        N = c;
        vector<vector<int>> dp(r, vector<int>(c, 0));
        dp[r-1][c-1] = 1;

        if(obstacleGrid[0][0] == 1)
            return 0;

        return recur(obstacleGrid, 0, 0, dp);
    }
    /*************************************************************
    int count;
    int r,c;
    void recur(vector<vector<int>>& og, int i, int j){
        if(i == r-1 and j == c-1)
            count++;
        if(j < c - 1 and og[i][j+1] == 0)
            recur(og, i, j+1);
        if(i < r - 1 and og[i+1][j] == 0)
            recur(og, i+1, j);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        r = obstacleGrid.size();
        c = obstacleGrid[0].size();
        vector<vector<int>> dp(r, vector<int>(c, 0));
        if(obstacleGrid[0][0] == 1)
            return 0;
        //int i = 0, j = 0;
        count = 0;
        recur(obstacleGrid, 0, 0);
        return count;
    }*/
};