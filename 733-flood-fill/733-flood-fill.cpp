class Solution {
public:
    void dfs(vector<vector<int>>& image, int i, int j, int& color, int& start_color){
        
        if(i >= image.size() or j >= image[0].size() or j < 0 or i < 0 or (!(image[i][j] == start_color)))
            return;
        
        image[i][j] = color; // Marking as visited.
        
        dfs(image, i+1, j, color, start_color);
        dfs(image, i, j+1, color, start_color);
        dfs(image, i-1, j, color, start_color);
        dfs(image, i, j-1, color, start_color);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int start_color = image[sr][sc];
        if(start_color == color)
            return image;
        dfs(image, sr, sc, color, start_color);
        return image;
    }
};

        /*for(int q = 0; q < grid.size(); q++){
            for(int w = 0; w < grid[0].size(); w++){
                cout << grid[q][w] << " ";
            }
            cout << "\n";
        }*/