// Last updated: 8/30/2025, 8:21:06 PM
class Solution {
public:
    vector<int> searchRange(vector<int>& arr, int x) 
    {
        int result1 = -1;
        int l = 0, r = arr.size() - 1;
        while(l <= r)
        {
            int mid = l + (r - l)/2; // to prevent overflow
            if(arr[mid] == x)
            {
                result1 = mid;
                r = mid - 1;
            }
            else if (arr[mid] < x)
                l = mid + 1;
            else
                r = mid - 1;
        } 

        // Last occurance
        int result2 = -1;
        l = 0, r = arr.size() - 1;
        while(l <= r)
        {
            int mid = l + (r - l)/2; // to prevent overflow
            if(arr[mid] == x)
            {
                result2 = mid;
                l = mid + 1;
            }
            else if (arr[mid] < x)
                l = mid + 1;
            else
                r = mid - 1;
        } 
        
        return {result1, result2};
    }
};