// Last updated: 8/30/2025, 8:17:58 PM
class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int m = 0;
        vector<vector<int>> res;
        vector<int> sq;
        int r = grid.size();
        int c = r;
        
        for(int i = 0; i < r - 2; i++)
        {
            vector <int> temp;
            for(int j = 0; j < c - 2; j++)
            {
                for(int k = i; k < i + 3; k++)
                    for(int l = j; l < j + 3; l++)
                        sq.push_back(grid[k][l]);
                temp.push_back(*max_element(sq.begin(), sq.end()));
                sq.clear();
            }
            res.push_back(temp);
        }
        return res;
        
    }
};