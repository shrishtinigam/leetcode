//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long int count(int coins[], int n, int sum) {
        
        long long dp[n+1][sum+1];
        
        for(long long i = 0; i < n+1; i++){
            for(long long j = 0; j < sum+1; j++){
                if(j == 0)
                    dp[i][j] = 1;
                else if(i == 0 and j != 0)
                    dp[i][j] = 0;
            }
        }
        
        for(long long i = 1; i < n+1; i++){
            for(long long j = 1; j < sum+1; j++){
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

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends