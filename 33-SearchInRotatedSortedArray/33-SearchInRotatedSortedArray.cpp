// Last updated: 8/30/2025, 8:21:07 PM
class Solution {
public:
    int FindMinElement(vector<int>arr)
    {
        if(arr.size() == 1)
            return 0;
        int l = 0, r = arr.size() - 1, mid;
        while(l <= r)
        {
            mid = l + (r - l)/2;
            int arr_mid_next = (mid + 1) % arr.size();
            int arr_mid_prev = (mid + arr.size() - 1) % arr.size();
            if(arr[mid] < arr[arr_mid_prev] && arr[mid] < arr[arr_mid_next])
                return mid;
            else if (arr[mid] >= arr[arr.size()-1]) 
                l = mid + 1;
            else
                r = mid - 1;
        } 
        return -1;
    } 
    
    int BinarySearch(vector<int>arr, int l, int r, int x)
    {
        if (arr.size() == 1)
        {
            if(arr[arr.size() - 1] == x)
                return 0;
            else
                return -1;
        }
        
        while(l <= r)
        {
            int mid = l + (r - l)/2;
            if(arr[mid] == x)
                return mid;
            else if (arr[mid] < x)
                l = mid + 1;
            else
                r = mid - 1;
        } 
        return -1; 
    }
    int search(vector<int>& arr, int x) {
        int index = FindMinElement(arr);
        if(x <= arr[arr.size()-1])
            return BinarySearch(arr, index, arr.size() - 1, x);
        return BinarySearch(arr, 0, index - 1, x);
    }
};