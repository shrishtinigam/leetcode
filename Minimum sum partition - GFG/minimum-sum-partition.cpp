//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    int sum = accumulate(arr, arr+n, 0);
	    
	    bool dp[n+1][(sum/2) + 1];
	    
	    for(int i = 1; i <= (sum/2); i++)
	        dp[0][i] = false;
	    for(int i = 0; i <= n; i++)
	        dp[i][0] = true;
	   
	    for(int i = 1; i < n+1; i++){
	       for(int j = 1; j < (sum/2)+1; j++){
	           if(arr[i-1] > j)
	                dp[i][j] = dp[i-1][j];
	           else
	                dp[i][j] = dp[i-1][j] or dp[i-1][j-arr[i-1]];
	            
	       }
	   }
	   int max_s1 = INT_MIN;
	   for(int i = 0; i <= sum/2; i++){
	       if(dp[n][i] == true)
	            if(max_s1 < i)
	                max_s1 = i;
	   }
	   return (sum - 2*max_s1);
	   
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends