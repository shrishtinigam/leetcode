class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j, int& c, int& s){
        
        if(i >= grid.size() or j >= grid[0].size() or j < 0 or i < 0 or (!(grid[i][j] == s)))
            return;
        
        grid[i][j] = c; // Marking as visited.
        
        dfs(grid, i+1, j, c, s);
        dfs(grid, i, j+1, c, s);
        dfs(grid, i-1, j, c, s);
        dfs(grid, i, j-1, c, s);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int s = image[sr][sc];
        if(s == color)
            return image;
        dfs(image, sr, sc, color, s);
        return image;
    }
};

        /*for(int q = 0; q < grid.size(); q++){
            for(int w = 0; w < grid[0].size(); w++){
                cout << grid[q][w] << " ";
            }
            cout << "\n";
        }*/