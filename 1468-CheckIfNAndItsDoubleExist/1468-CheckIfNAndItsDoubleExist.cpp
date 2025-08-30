// Last updated: 8/30/2025, 8:18:15 PM
class Solution {
public:
    int binarySearch(vector<int>& arr, int l, int r, int x)
    {
        if (r >= l) {
            int mid = l + (r - l) / 2;
            if (arr[mid] == x)
                return mid;
            if (arr[mid] > x)
                return binarySearch(arr, l, mid - 1, x);
            return binarySearch(arr, mid + 1, r, x);
        }
        return -1;
    }
    bool checkIfExist(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        for(int i = 0; i < arr.size(); i++)
        {
            int index = binarySearch(arr, 0, arr.size()-1, 2*arr[i]);
            if(index != -1 && index != i)
                return true;
        }
        return false;
    }
};