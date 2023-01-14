//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
  public:
    vector <int> subsetSum_Valid_S1(int arr[], int sum, int n){
        vector<vector<bool>> t(n + 1, vector<bool>(sum + 1, false)); 
        for(int i = 0; i < sum+1; i++)
            t[0][i] = false;
        for(int i = 0; i < n+1; i++)
            t[i][0] = true;
        
        for(int i = 1; i < n + 1; i++){
            for(int j = 1; j < sum + 1; j++){
                if(arr[i-1] > j)
                    t[i][j] = t[i-1][j];
                else if(arr[i-1] <= j)
                    t[i][j] = (t[i-1][j] || t[i-1][j-arr[i-1]]);
            }
        }
        vector<int> valid_S1;
        for(int i = 0; i < sum+1; i++){
            if(t[n][i] == true)
                valid_S1.push_back(i);
        }
        return valid_S1;
    }
	int minDifference(int arr[], int n)  { 
	    int sum = accumulate(arr, arr + n, 0);
	    // cout << "sum: " << sum << "\n";
	    vector<int> valid_S1 = subsetSum_Valid_S1(arr, sum/2, n);
	    // for (int i = 0; i < valid_S1.size(); i++)
	        // cout << valid_S1[i] << " ";
	    // cout << "\n";
	    int minDiff = sum - 2*valid_S1[valid_S1.size()-1];
	    return minDiff;
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