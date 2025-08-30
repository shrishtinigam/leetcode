// Last updated: 8/30/2025, 8:20:26 PM
class Solution {
public:
    
    bool search(vector<int>& arr, int x) 
    {
        int l(0), r(arr.size()-1), n(arr.size());
        if(n == 1)
        {
            if(x == arr[0])
                return true;
            return false;
        }
        
        while(l <= r)
        {
            while(l < r && arr[l] == arr[r]) 
                l++;
            int mid = (l+r)/2;
            if(arr[l] == x || arr[r] == x || arr[mid] == x)
                return true;
            if(arr[l] <= arr[mid]) // left side is sorted
            {
                if(arr[l] < x && x < arr[mid])
                    r = mid - 1;
                else
                    l = mid + 1;
            }
            else if(arr[mid] <= arr[r]) // right side is sorted
            {
                if(arr[mid] < x && x < arr[r])
                    l = mid + 1;
                else
                    r = mid - 1;
            }
            else
                l++;
        }
        return false;
    }
};