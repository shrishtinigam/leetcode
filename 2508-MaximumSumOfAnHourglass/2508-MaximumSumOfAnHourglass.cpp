// Last updated: 8/30/2025, 8:17:50 PM
class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int maxHourglass = 0;
        int currHourglass = 0;
        
        for(int i = 0; i < r - 2; i++){
            for(int j = 0; j < c - 2; j++){
                currHourglass = grid[i][j] + grid[i][j+1] + grid[i][j+2] + grid[i+1][j+1] + grid[i+2][j] + grid[i+2][j+1] + grid[i+2][j+2];
                maxHourglass = max(currHourglass, maxHourglass);
                cout << maxHourglass << endl;
            }
        }
        return maxHourglass;
    }
};