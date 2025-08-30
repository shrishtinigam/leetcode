// Last updated: 8/30/2025, 8:20:33 PM
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty())
            return false;
        int m = matrix.size(), n = matrix[0].size();
        int start = 0, end = m*n - 1;
        while(start <= end)
        {
            int mid = start + (end - start)/2;
            int e = matrix[mid/n][mid%n];
            if(target < e)
                end = mid - 1;
            else if(target > e)
                start = mid + 1;
            else
                return true;
        }
        return false;
    }
};

/*
 int ROWS(matrix.size()), COLS(matrix[0].size()); 
        int top(0), bot(ROWS-1);

        while(top <= bot){
            int row = (top + bot) / 2;
            if(target > matrix[row][COLS-1])
                top = row + 1;
            else if(target < matrix[row][0])
                bot = row - 1;
            else
                break;
        }

        if(!(top <= bot))
            return false;

        int row = (top + bot) / 2;
        int l(0), r(COLS-1);
        while(l <= r){
            int m = (l + r)/2;
            if(target > matrix[row][m])
                l = m + 1;
            else if(target < matrix[row][m])
                r = m - 1;
            else
                return true;
        }
        return false;


*/