class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int col0 = 1, rows = matrix.size(), cols = matrix[0].size();
        
        for(int i = 0; i < rows; i++)
        {
            if(matrix[i][0] == 0) 
                col0 = 0;
            for(int j = 1; j < cols; j++)
                if(matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
        }
        for(int i = rows - 1; i >= 0; i--)
        {
            for(int j = cols - 1; j >= 1; j--)
                if(matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            if(col0 == 0)
                matrix[i][0] = 0;

        }
    }
};

/*

        set <int> rows_set;
        set <int> cols_set;
        int rows = matrix.size();
        int cols = matrix[0].size();
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                if(matrix[i][j] == 0)
                {
                    rows_set.insert(i);
                    cols_set.insert(j);
                }
            }
        }
        vector <int> zeroes(cols, 0);
        set<int> :: iterator it;
        for(it = rows_set.begin() ; it != rows_set.end() ; it++)
        {
            matrix[*it] = zeroes;
        }
        for(it = cols_set.begin() ; it != cols_set.end() ; it++)
        {
            for(int j = 0; j < rows; j++)
            {
                matrix[j][*it] = 0;
            }
        }
*/