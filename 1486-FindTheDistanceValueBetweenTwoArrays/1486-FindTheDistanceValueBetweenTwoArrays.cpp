// Last updated: 8/30/2025, 8:18:13 PM
class Solution {
public:
    int binarySearchRange(vector<int>& arr, int l, int r, int startRange, int endRange)
    {
        if (r >= l) {
            int mid = l + (r - l) / 2;
            if (arr[mid] >= startRange && arr[mid] <= endRange)
                return mid;
            if (arr[mid] > endRange)
                return binarySearchRange(arr, l, mid - 1, startRange, endRange);
            return binarySearchRange(arr, mid + 1, r, startRange, endRange);
        }
        return -1;
    }
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr1.begin(), arr1.end());
        sort(arr2.begin(), arr2.end());
        int result = 0;
        for(int i = 0; i < arr1.size(); i++)
        {
            int startRange = arr1[i] - d;
            int endRange = arr1[i] + d;
            int index = binarySearchRange(arr2, 0, arr2.size()-1, startRange, endRange);
            if(index == -1)
                result++;
        }
        return result;

    }
};