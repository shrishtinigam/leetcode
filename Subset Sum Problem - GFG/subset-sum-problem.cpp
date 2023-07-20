//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   


public:

    bool subsetSum(vector<int> &arr, int sum, int n,vector<vector<int>>& dp){
        if(n == 0 and sum != 0)
            return 0;
        if(sum == 0)
            return 1;
            
        if(dp[n][sum] != -1)
            return dp[n][sum];
        
        if(arr[n-1] > sum)
            return dp[n][sum] = subsetSum(arr, sum, n-1, dp);
        return dp[n][sum] = subsetSum(arr, sum, n-1, dp) or subsetSum(arr, sum-arr[n-1],n-1,dp);
    }
    /*bool isSubsetSum(vector<int>arr, int sum){
        vector<vector<int>>dp(arr.size()+1,vector<int>(sum+1,-1));
        return subsetSum(arr,sum,arr.size(),dp);
    }*/
    
    bool isSubsetSum(vector<int>arr, int sum){
        int n = arr.size();
        int dp[n+1][sum+1];
        
        for(int i = 1; i < sum+1; i++)
            dp[0][i] = 0;
        for(int i = 0; i < n+1; i++)
            dp[i][0] = 1;
        
        
        for(int i = 1; i < n+1; i++){
            for(int j = 1; j < sum+1; j++){
                if(arr[i-1] > j)
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j] or dp[i - 1][j - arr[i-1]];
            }
        }
        
        return dp[n][sum];
        
    }
    
};








/*
 * int checkSubsetSum(vector<int>&arr,int sum,int n,vector<vector<int>>&dp){
        if(n==0 and sum==0){
            return 1;
        }
        else if(n==0 and sum!=0){
            return 0;
        }
        if(dp[n][sum]!=-1){
            return dp[n][sum];
        }
        if(arr[n-1]>sum){ 
            return dp[n][sum]=checkSubsetSum(arr,sum,n-1,dp);
        }
        else{
            return dp[n][sum]=checkSubsetSum(arr,sum-arr[n-1],n-1,dp)||checkSubsetSum(arr,sum,n-1,dp);
        }
    }
*/

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends