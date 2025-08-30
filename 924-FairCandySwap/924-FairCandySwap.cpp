// Last updated: 8/30/2025, 8:18:27 PM
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
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int sumAlice = accumulate(aliceSizes.begin(), aliceSizes.end(), 0);
        int sumBob = accumulate(bobSizes.begin(), bobSizes.end(), 0);
        int delta = (sumBob - sumAlice)/2;
        sort(bobSizes.begin(), bobSizes.end());
        for(int i = 0; i < aliceSizes.size(); i++)
        {
            int alicePart = aliceSizes[i];
            int index = binarySearch(bobSizes, 0, bobSizes.size(), alicePart+delta);
            if(index != -1)
            {
                vector <int> arr{alicePart, bobSizes[index]};
                return arr;
            }
        }
        vector <int> arr{0,0};
        return arr;
    }
};