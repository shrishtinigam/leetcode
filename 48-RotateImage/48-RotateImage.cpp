// Last updated: 8/30/2025, 8:20:54 PM
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int top = 0, bottom = matrix.size() - 1; 
        while(top < bottom)
        {
            matrix[top].swap(matrix[bottom]);
            top++;
            bottom--;
        }
        
        for(int i = 1; i < matrix.size(); i++)
        {
            for(int j = 0; j < i; j++)
            {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
    }
};
