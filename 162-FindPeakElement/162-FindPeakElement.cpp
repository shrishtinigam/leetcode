// Last updated: 8/30/2025, 8:19:41 PM
class Solution {
public:
    int findPeakElement(vector<int>& arr) 
    {
        if(arr.size() == 1)
            return 0;
        int l(0), r(arr.size()-1);
        while(l <= r)
        {
            int mid = l + (r - l)/2;
            if(mid == 0)
            {
                if(arr[0] > arr[1])
                    return 0;
                return 1;
            }
            if(mid == arr.size() - 1)
            {
                if(arr[arr.size() - 1] > arr[arr.size() - 2])
                    return arr.size() - 1;
                return arr.size() - 2;
            }
            if(arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
                return mid;
            else if(arr[mid + 1] >= arr[mid])
                l = mid + 1;
            else
                r = mid - 1;
        }
        return -1;
    }
};