// Last updated: 8/30/2025, 8:19:33 PM
class Solution {
    
public:
    
    void dfs(vector<vector<char>>& grid, int i, int j){
        
        if(i >= grid.size() or j >= grid[0].size() or j < 0 or i < 0 or grid[i][j]=='0')
            return;
        
        grid[i][j] = '0'; // Marking as visited.
        
        dfs(grid, i+1, j);
        dfs(grid, i, j+1);
        dfs(grid, i-1, j);
        dfs(grid, i, j-1);
    }
 
    int numIslands(vector<vector<char>>& grid) {
        
        int num = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == '1'){
                    dfs(grid, i, j);
                    num++;    
                }
            }
        }
        
        return num;
    }
    Solution(){
        ios_base::sync_with_stdio(false);
        cin.tie(0);
    }
};


/*
class Solution {
public:
    
    void bfs(vector<vector<char>>& grid, vector <vector<int>>& visited, int i, int j){
        if(i >= grid.size() or j >= grid[0].size() or j < 0 or i < 0)
            return;
        if(grid[i][j] == '1' and !find(visited, {i, j}))
            visited.push_back({i,j});
        else
            return;
        bfs(grid, visited, i+1, j);
        bfs(grid, visited, i, j+1);
        bfs(grid, visited, i-1, j);
        bfs(grid, visited, i, j-1);

    }
    bool find(vector <vector<int>> v, vector <int> x){
        for(auto i : v)
            if(i == x)
                return true;
        return false;
    }
    int numIslands(vector<vector<char>>& grid) {
        vector <vector<int>> visited;
        int num = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == '1' and !find(visited, {i, j})){
                    bfs(grid, visited, i, j);
                    num++;    
                }
            }
        }
        return num;
    }
};
*/