// Last updated: 8/30/2025, 8:18:21 PM
class Solution {
public:
    
   
    int longestCommonSubsequence(string text1, string text2) {

        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp (n+1, vector<int>(m+1, -1));
        for(int i = 0; i < n+1; i++)
            dp[i][0] = 0;
        for(int i = 0; i < m+1; i++)
            dp[0][i] = 0;

        for(int i = 1; i < n + 1; i++){
            for(int j = 1; j < m + 1; j++){
                if(text1[i-1] == text2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }

        return dp[n][m];
    }
};


/*
int recur(string &s1, string &s2, int n, int m, vector<vector<int>>& dp){
        if(n == 0 or m == 0)
            return 0;
        if(dp[n][m] != -1)
            return dp[n][m];
        if(s1[n-1] == s2[m-1])
            return dp[n][m] = 1 + recur(s1, s2, n-1, m-1, dp);
        else
            return dp[n][m] = max(recur(s1, s2, n-1, m, dp), recur(s1,s2,n,m-1, dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp (text1.size()+1, vector<int>(text2.size()+1, -1));
        return recur(text1, text2, text1.size(), text2.size(), dp);
    }
*/