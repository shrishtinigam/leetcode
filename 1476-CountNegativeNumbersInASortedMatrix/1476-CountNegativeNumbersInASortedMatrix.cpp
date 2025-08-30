// Last updated: 8/30/2025, 8:18:14 PM
class Solution {
public:
    
    int BinarySearch(vector<int>arr)
    {
        int result = -1;
        int l = 0, r = arr.size() - 1;
        while(l <= r)
        {
            int mid = l + (r - l)/2;
            if(arr[mid] < 0)
            {
                result = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        } 
        return result;
  }
    int countNegatives(vector<vector<int>>& grid) {
        int count = 0;
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0; i < n; i++)
        {
            int x = BinarySearch(grid[i]);
            if(x != -1)
                count += m - x;
        }
        return count;
    }
};