class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        int rows = board.size(), cols = board[0].size();
        int m[9] = {0};
        
        // Rows
        for(int i = 0; i < rows; i++)
        {
            memset(m, 0, sizeof(m));
            for(int j = 0; j < cols; j++)
            {
                char x = board[i][j];
                if(x != '.')
                {
                    int y = x - '0';
                    if(m[y-1] == 1)
                        return false;
                    m[y-1] = 1;
                }
            }
        }
        // Cols
        for(int i = 0; i < rows; i++)
        {
            memset(m, 0, sizeof(m));
            for(int j = 0; j < cols; j++)
            {
                char x = board[j][i];
                if(x != '.')
                {
                    int y = x - '0';
                    if(m[y-1] == 1)
                        return false;
                    m[y-1] = 1;
                }
            }
        }
        
        // Squares
        int r = 0, c = 0;
        for(int k = 0; k < 9; k++)
        {
            memset(m, 0, sizeof(m));
            for(int i = r; i < r + 3; i++)
            {
                for(int j = c; j < c + 3; j++)
                {
                    cout << board[i][j] << " ";
                    char x = board[i][j];
                    if(x != '.')
                    {
                        int y = x - '0';
                        if(m[y-1] == 1)
                            return false;
                        m[y-1] = 1;
                    }
                }
            }
            if((k + 1) % 3 == 0)
                r += 3;
            c += 3;
            if(c == 9)
                c = 0;
        }
        return true;
    }
};