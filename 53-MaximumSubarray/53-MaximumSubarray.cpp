// Last updated: 8/30/2025, 8:20:50 PM
class Solution {
public:
    int maxSubArray(vector<int>& arr) 
    
    {
            int max = INT_MIN;
            int sum = 0;
            int n = arr.size();
            for(int i = 0; i < n; i++)
            {
                sum = sum + arr[i];
                if(sum > max)
                    max = sum;
                if(sum < 0)
                    sum = 0;
            }      
            return max;
        }
};