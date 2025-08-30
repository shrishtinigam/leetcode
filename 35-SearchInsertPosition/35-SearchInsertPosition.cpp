// Last updated: 8/30/2025, 8:21:05 PM
class Solution {
public:
    int searchInsert(vector<int>& arr, int x) {
    int l = 0, r = arr.size() - 1;
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
    return l;
    }
};