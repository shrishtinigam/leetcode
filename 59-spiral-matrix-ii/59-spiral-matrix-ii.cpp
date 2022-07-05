class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int m = n;
        int left = 0, right = m - 1, bottom = n - 1, top = 0;
        int direction = 1;
        vector<vector<int>> v( n, vector<int> (m, 0));
        int number = 1;
        while(left <= right && top <= bottom)
        {
            if(direction == 1) // towards right
            {
                for(int i = left; i <= right; i++) 
                    v[top][i] = number++;
                direction = 2;
                top++;
            }
            
            else if(direction == 2) // downwards
            {
                for(int i = top; i <= bottom; i++) 
                     v[i][right] = number++;
                direction = 3;
                right--;
            }
            
            else if(direction == 3) // towards left
            {
                for(int i = right; i >= left; i--) 
                     v[bottom][i] = number++;
                direction = 4;
                bottom--;
            }
            
            else if(direction == 4) // upwards
            {
                for(int i = bottom; i >= top; i--) 
                     v[i][left] = number++;
                direction = 1;
                left++;
            }
        }
        return v;
    }
};